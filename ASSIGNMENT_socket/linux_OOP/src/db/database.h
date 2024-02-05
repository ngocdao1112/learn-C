#ifndef SRC_DB_DATABASE_H_
#define SRC_DB_DATABASE_H_

#include <string>
#include <fstream>
#include <cstdlib>
#include <stdexcept>
using namespace std;

template <class T>
class Database {
public:
    Database(
        const string &_directory,
        const string &_primaryKey,
        pair<int, int> _bucketHash = {0, 2})
        :pk(_primaryKey), dbDir(_directory), bucketHash(_bucketHash)
        {
            if(dbDir.back() != '/') 
                dbDir.append("/");
            createDbDir();
        }

    // append an entry of class T (specializes Entry) to database
    int add(const T &) const;

    // get an entry where primary key value is value
    // uses linear search
    pair<T, int> get(const string &value) const;

    // update an entry in database
    bool update(const T &oldEntry, const T &newEntry) const;

    // mark an entry as "deleted"
    bool remove(const T & entry) const;

private:
    // primary key
    string pk;

    // where to save database files
    string dbDir;

    // bucket name is substring of pk at these indices
    pair<int, int> bucketHash;

    // get name of bucket for a pk value using bucketHash
    string getBucketName(const string &pkValue) const {
        return dbDir + pkValue.substr(bucketHash.first, bucketHash.second) + ".txt";
    }

    // create a bucket if not exists
    bool createBucket(const string &bucketName) const;

    // get number of records in a bucket
    int getNumberOfRecords(fstream &bucket, const T &entry);

    // create the database directory
    void createDbDir();

    // helper function for add(const T&). uses binary search
    int getInsertPosition(fstream &bucket, const T &entry);
};

template <class T>
void Database<T>::createDbDir() {
    // TODO: Add support for other OS
    string cmd("mkdir -p " + dbDir);
    const int st = system(cmd.c_str());
    if (st > 1) {
        throw runtime_error("Failed to create database directory.");
    }
}

template <class T>
bool Database<T>::createBucket(const string &bucketName) const {
    ifstream fl(bucketName);
    if (fl) 
        return false;   // not created
    ofstream fout(bucketName);
    return true;
}

template <class T>
int Database<T>::getNumberOfRecords(fstream &bucket, const T& entry) {
    bucket.seekg(0, ios::end);
    const int num = bucket.tellg() / entry.size();
    bucket.seekg(0);
    return num;
}

template <class T>
int Database<T>::add(const T &entry) const {
    pair<T, int> old = get(entry.get(pk));
    if (old.second != -1) 
        return 1;
    const string bucketName = getBucketName(entry.get(pk));
    createBucket(bucketName);
    ofstream bucket(bucketName, ios::app | ios::binary);
    bucket << entry.serialize() + "\n";
    return 0;
}

template <class T>
pair<T, int> Database<T>::get(const string &value) const {
    string record;
    ifstream bucket(getBucketName(value), ios::binary);
    while (getline(bucket, record) && !record.empty()) {
        T temp(record);
        if (temp.get(pk) == value) {
            return {temp, bucket.tellg()};
        }
    }
    return {T(), -1};
}

template <class T>
bool Database<T>::update(const T &oldEntry, const T &newEntry) const {
    using pair;
    using ofstream;

    pair<T, int> old = get(oldEntry.get(pk));

    // do not update if some entry already exists with newEntry.pk
    // while allowing self to be updated
    pair<T, int> same = get(newEntry.get(pk));
    if (same.second != -1 && same.second != old.second) {
        return false;
    }

    ofstream bucket(
        getBucketName(oldEntry.get(pk)),
        ios::in | ios::out | ios::binary);
    auto offset = old.second - oldEntry.size() - 1;
    bucket.seekp(offset);
    bucket << newEntry.serialize() + "\n";
    return true;
}

#endif  //  SRC_DB_DATABASE_H_