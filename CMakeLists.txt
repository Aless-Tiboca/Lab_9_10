cmake_minimum_required(VERSION 3.21)
project(Lab_9_10)

set(CMAKE_CXX_STANDARD 14)

add_executable(Lab_9_10 main.cpp
        Domain/Ticket.cpp Domain/Ticket.h
        Repository/RepoInMemory.cpp Repository/RepoInMemory.h
        Repository/IRepo.h
        Service/TicketService.h Service/TicketService.cpp
        UI/Console.cpp UI/Console.h
        Tests/tests.cpp Tests/tests.h
        Repository/RepoInFile.h
        Repository/RepoInFile.cpp)
