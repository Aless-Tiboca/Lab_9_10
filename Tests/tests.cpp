//
// Created by alext on 21/04/2022.
//

#include <cassert>
#include "tests.h"
#include "../Domain/Ticket/Ticket.h"
#include "../Repository/RepoInMemory.h"
#include "../Repository/RepoInFile.h"
#include "../Service/TicketService.h"

void testAll() {
    testTicket();
    testRepoInMemory();
    testRepoInFile();
    testTicketService();
}

void testTicket() {
    testTicketGet();
    testTicketSet();
}

void testTicketGet() {
    Ticket ticket(12, "Luni", "CJ-SB", 12);
    assert(ticket.getCod() == "CJ-SB");
    assert(ticket.getId() == 12);
    assert(ticket.getPret() == 12);
    assert(ticket.getZiua() == "Luni");
}

void testTicketSet() {
    Ticket ticket(1);
    ticket.setCod("CJ-SB");
    ticket.setPret(12);
    ticket.setZiua("Luni");
    assert(ticket.getCod() == "CJ-SB");
    assert(ticket.getId() == 1);
    assert(ticket.getPret() == 12);
    assert(ticket.getZiua() == "Luni");
}

void testRepoInMemoryAdd() {
    RepoInMemory<Ticket> repository;

    Ticket p1(1, "Luni", "c2", 3);
    Ticket p2(2, "Marti", "s3", 5);
    Ticket p3(3, "Luni", "ci4", 7);
    Ticket p4(4, "Joi", "45d", 4);
    Ticket p5(5, "Luni","fr4" , 3);

    repository.create(p1);
    repository.create(p2);
    repository.create(p3);
    repository.create(p4);
    repository.create(p5);

    assert(repository.getAll()[0] == p1);
    assert(repository.getAll()[1] == p2);
    assert(repository.getAll()[2] == p3);
    assert(repository.getAll()[3] == p4);
    assert(repository.getAll()[4] == p5);
}

void testRepoInMemory() {
    testRepoInMemoryAdd();
    testRepoInMemoryGetAll();
    testRepoInMemoryDelete();
    testRepoInMemoryUpdate();
}

void testRepoInMemoryGetAll() {
    RepoInMemory<Ticket> repository;

    Ticket p1(1, "Luni", "c2", 3);
    Ticket p2(2, "Marti", "s3", 5);
    Ticket p3(3, "Luni", "ci4", 7);
    Ticket p4(4, "Joi", "45d", 4);
    Ticket p5(5, "Luni","fr4" , 3);

    repository.create(p1);
    repository.create(p2);
    repository.create(p3);
    repository.create(p4);
    repository.create(p5);

    assert(repository.getAll().size() == 5);
}

void testRepoInMemoryUpdate() {
    RepoInMemory<Ticket> repository;

    Ticket p1(1, "Luni", "c2", 3);
    Ticket p2(2, "Marti", "s3", 5);
    Ticket p3(3, "Luni", "ci4", 7);
    Ticket p4(4, "Joi", "45d", 4);
    Ticket p5(5, "Luni","fr4" , 3);

    repository.create(p1);
    repository.create(p2);
    repository.create(p3);
    repository.create(p4);
    repository.create(p5);

    repository.update(1, Ticket(1, "Marti", "FFF", 10));

    assert(repository.getAll()[0].getCod() == "FFF");
    assert(repository.getAll()[0].getId() == 1);
    assert(repository.getAll()[0].getPret() == 10);
    assert(repository.getAll()[0].getZiua() == "Marti");
}

void testRepoInMemoryDelete() {
    RepoInMemory<Ticket> repository;

    Ticket p1(1, "Luni", "c2", 3);
    Ticket p2(2, "Marti", "s3", 5);
    Ticket p3(3, "Luni", "ci4", 7);
    Ticket p4(4, "Joi", "45d", 4);
    Ticket p5(5, "Luni","fr4" , 3);

    repository.create(p1);
    repository.create(p2);
    repository.create(p3);
    repository.create(p4);
    repository.create(p5);

    repository.deleteEntity(2);
    repository.deleteEntity(4);
    repository.deleteEntity(5);
    assert(repository.getAll().size() == 2);
}

void testRepoInFile() {
    testRepoInFileAdd();
    testRepoInFileGetAll();
    testRepoInFileUpdate();
    testRepoInFileDelete();
}

void testRepoInFileAdd() {
    RepoInFile<Ticket> repository("runTest.txt");

    Ticket p1(1, "Luni", "c2", 3);
    Ticket p2(2, "Marti", "s3", 5);
    Ticket p3(3, "Luni", "ci4", 7);
    Ticket p4(4, "Joi", "45d", 4);
    Ticket p5(5, "Luni","fr4" , 3);

    repository.create(p1);
    repository.create(p2);
    repository.create(p3);
    repository.create(p4);
    repository.create(p5);

    assert(repository.getAll()[0] == p1);
    assert(repository.getAll()[1] == p2);
    assert(repository.getAll()[2] == p3);
    assert(repository.getAll()[3] == p4);
    assert(repository.getAll()[4] == p5);
    repository.clearFile();
}

void testRepoInFileGetAll() {
    RepoInFile<Ticket> repository("runTest.txt");

    Ticket p1(1, "Luni", "c2", 3);
    Ticket p2(2, "Marti", "s3", 5);
    Ticket p3(3, "Luni", "ci4", 7);
    Ticket p4(4, "Joi", "45d", 4);
    Ticket p5(5, "Luni","fr4" , 3);

    repository.create(p1);
    repository.create(p2);
    repository.create(p3);
    repository.create(p4);
    repository.create(p5);

    assert(repository.getAll().size() == 5);
    repository.clearFile();
}

void testRepoInFileDelete() {
    RepoInFile<Ticket> repository("runTest.txt");

    Ticket p1(1, "Luni", "c2", 3);
    Ticket p2(2, "Marti", "s3", 5);
    Ticket p3(3, "Luni", "ci4", 7);
    Ticket p4(4, "Joi", "45d", 4);
    Ticket p5(5, "Luni","fr4" , 3);

    repository.create(p1);
    repository.create(p2);
    repository.create(p3);
    repository.create(p4);
    repository.create(p5);

    repository.deleteEntity(2);
    repository.deleteEntity(4);
    repository.deleteEntity(5);
    assert(repository.getAll().size() == 2);
    repository.clearFile();
}

void testRepoInFileUpdate() {
    RepoInFile<Ticket> repository("runTest.txt");

    Ticket p1(1, "Luni", "c2", 3);
    Ticket p2(2, "Marti", "s3", 5);
    Ticket p3(3, "Luni", "ci4", 7);
    Ticket p4(4, "Joi", "45d", 4);
    Ticket p5(5, "Luni","fr4" , 3);

    repository.create(p1);
    repository.create(p2);
    repository.create(p3);
    repository.create(p4);
    repository.create(p5);

    repository.update(1, Ticket(1, "Marti", "FFF", 10));

    assert(repository.getAll()[0].getCod() == "FFF");
    assert(repository.getAll()[0].getId() == 1);
    assert(repository.getAll()[0].getPret() == 10);
    assert(repository.getAll()[0].getZiua() == "Marti");
    repository.clearFile();
}

void testTicketService() {
    testTicketServiceAdd();
    testTicketServiceUpdate();
    testTicketServiceDelete();
    testTicketServiceSumFromADay();
}

void testTicketServiceAdd() {
    RepoInMemory<Ticket> repoInMemory;
    TicketService ser(repoInMemory);

    Ticket p1(1, "Luni", "c2", 3);
    Ticket p2(2, "Marti", "s3", 5);
    Ticket p3(3, "Luni", "ci4", 7);
    Ticket p4(4, "Joi", "45d", 4);
    Ticket p5(5, "Luni","fr4" , 3);

    ser.create(p1);
    ser.create(p2);
    ser.create(p3);
    ser.create(p4);
    ser.create(p5);

    assert(ser.getAll()[0] == p1);
    assert(ser.getAll()[1] == p2);
    assert(ser.getAll()[2] == p3);
    assert(ser.getAll()[3] == p4);
    assert(ser.getAll()[4] == p5);
}

void testTicketServiceSumFromADay() {
    RepoInMemory<Ticket> repoInMemory;
    TicketService ser(repoInMemory);

    Ticket p1(1, "Luni", "c2", 3);
    Ticket p2(2, "Marti", "s3", 5);
    Ticket p3(3, "Luni", "ci4", 7);
    Ticket p4(4, "Joi", "45d", 4);
    Ticket p5(5, "Luni","fr4" , 3);

    ser.create(p1);
    ser.create(p2);
    ser.create(p3);
    ser.create(p4);
    ser.create(p5);

    assert(ser.getSumOfTicketsFromADay("Luni") == 13);
}

void testTicketServiceDelete() {
    RepoInMemory<Ticket> repoInMemory;
    TicketService ser(repoInMemory);

    Ticket p1(1, "Luni", "c2", 3);
    Ticket p2(2, "Marti", "s3", 5);
    Ticket p3(3, "Luni", "ci4", 7);
    Ticket p4(4, "Joi", "45d", 4);
    Ticket p5(5, "Luni","fr4" , 3);

    ser.create(p1);
    ser.create(p2);
    ser.create(p3);
    ser.create(p4);
    ser.create(p5);

    ser.deleteTicket(2);
    ser.deleteTicket(4);
    ser.deleteTicket(5);
    assert(ser.getAll().size() == 2);
}

void testTicketServiceUpdate() {
    RepoInMemory<Ticket> repoInMemory;
    TicketService ser(repoInMemory);

    Ticket p1(1, "Luni", "c2", 3);
    Ticket p2(2, "Marti", "s3", 5);
    Ticket p3(3, "Luni", "ci4", 7);
    Ticket p4(4, "Joi", "45d", 4);
    Ticket p5(5, "Luni","fr4" , 3);

    ser.create(p1);
    ser.create(p2);
    ser.create(p3);
    ser.create(p4);
    ser.create(p5);

    ser.update(1, Ticket(1, "Marti", "FFF", 10));

    assert(ser.getAll()[0].getCod() == "FFF");
    assert(ser.getAll()[0].getId() == 1);
    assert(ser.getAll()[0].getPret() == 10);
    assert(ser.getAll()[0].getZiua() == "Marti");
}

