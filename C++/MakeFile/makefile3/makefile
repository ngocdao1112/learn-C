custom_target:
    echo "Hello from command1"
    echo "Executing command2"
    ifdef OS
        ifeq ($(OS),Windows_NT)
            mkdir custom_directory
        else
            mkdir -p custom_directory
        endif
    else
        mkdir -p custom_directory
    endif