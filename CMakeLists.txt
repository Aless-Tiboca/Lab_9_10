cmake_minimum_required(VERSION 3.21)
project(Lab_9_10)

set(CMAKE_CXX_STANDARD 14)

add_executable(Lab_9_10 main.cpp
        Domain/Ticket/Ticket.cpp Domain/Ticket/Ticket.h
        Repository/RepoInMemory.cpp Repository/RepoInMemory.h
        Repository/IRepo.h
        Service/TicketService.h Service/TicketService.cpp
        UI/Console.cpp UI/Console.h
        Tests/tests.cpp Tests/tests.h
        Repository/RepoInFile.h Repository/RepoInFile.cpp
        Domain/Exception.h
        Domain/Ticket/TicketValidator.cpp Domain/Ticket/TicketValidator.h
        Domain/Banknote/Banknote.cpp Domain/Banknote/Banknote.h
        Domain/Banknote/BanknoteValidator.cpp Domain/Banknote/BanknoteValidator.h
        Service/BanknoteService.cpp Service/BanknoteService.h
        Domain/DoubleCompare.h)
