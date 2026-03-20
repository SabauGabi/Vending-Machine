cmake_minimum_required(VERSION 3.30)
project(lab910)

set(CMAKE_CXX_STANDARD 20)

add_executable(lab910 main.cpp
        Entity/Entity.cpp
        Entity/Entity.h
        Repository/Repo.cpp
        Repository/Repo.h
        Test/tests.cpp
        Test/tests.h
        UI/UI.cpp
        UI/UI.h
        Service/Service.cpp
        Service/Service.h
        Repository/FileRepo.cpp
        Repository/FileRepo.h
        Validator/ValidationException.h
        Validator/Validator.h
        Validator/MyException.h)
