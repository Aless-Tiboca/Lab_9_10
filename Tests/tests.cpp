//
// Created by alext on 21/04/2022.
//

#include <cassert>
#include "tests.h"
#include "../Domain/Ticket/Ticket.h"
#include "../Service/TicketService.h"
#include "../Repository/RepoInFile.h"
#include "../Repository/RepoInMemory.h"
#include "../Service/BanknoteService.h"
#include "../Domain/Banknote/Banknote.h"

void testAll() {
    testTicket();
    testRepoInMemory();
    testRepoInFile();
    testTicketService();
//    testBanknoteService();
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

    ser.deleteTicket(1);
    ser.deleteTicket(2);
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

void testBanknoteService() {
    testBanknoteService();
    testBanknoteServiceAdd();
    testBanknoteServiceUpdate();
    testBanknoteServiceDelete();
}

void testBanknoteServiceAdd() {
    RepoInMemory<Banknote> repoInMemory;
    BanknoteService ser(repoInMemory);

    Banknote b1(1, 1, 12);
    Banknote b2(2, 0.5, 12);
    Banknote b3(3, 0.1, 12);
    Banknote b4(4, 10, 12);
    Banknote b5(5, 5, 12);

    ser.create(b1);
    ser.create(b2);
    ser.create(b3);
    ser.create(b4);
    ser.create(b5);

    assert(ser.getAll().size() == 5);
}

void testBanknoteServiceUpdate() {
    RepoInMemory<Banknote> repoInMemory;
    BanknoteService ser(repoInMemory);

    Banknote b1(1, 1, 12);
    Banknote b2(2, 0.5, 4);
    Banknote b3(3, 0.1, 1);
    Banknote b4(4, 10, 1);
    Banknote b5(5, 5, 11);

    ser.create(b1);
    ser.create(b2);
    ser.create(b3);
    ser.create(b4);
    ser.create(b5);

    ser.update(1, Banknote(1, 50, 10));

    assert(ser.getAll()[0].getId() == 1);
    assert(ser.getAll()[0].getValue() == 50);
    assert(ser.getAll()[0].getNoOccurrences() == 10);
}

void testBanknoteServiceDelete() {
    RepoInMemory<Banknote> repoInMemory;
    BanknoteService ser(repoInMemory);

    Banknote b1(1, 500, 10);
    Banknote b2(2, 200, 10);
    Banknote b3(3, 100, 10);
    Banknote b4(4, 50, 10);
    Banknote b5(5, 10, 10);
    Banknote b6(6, 5, 12);
    Banknote b7(7, 1, 1);
    Banknote b8(8, 0.5, 9);
    Banknote b9(9, 0.1, 7);
    Banknote b10(10, 0.05, 10);
    Banknote b11(11, 0.01, 10);

    ser.create(b1);
    ser.create(b2);
    ser.create(b3);
    ser.create(b4);
    ser.create(b5);
    ser.create(b6);
    ser.create(b7);
    ser.create(b8);
    ser.create(b9);
    ser.create(b10);
    ser.create(b11);

    ser.deleteBanknote(1);
    ser.deleteBanknote(2);
    assert(ser.getAll().size() == 9);
}

void testBanknoteServiceChange() {
    RepoInMemory<Banknote> repoInMemory;
    BanknoteService ser(repoInMemory);

    Banknote b1(1, 500, 10);
    Banknote b2(2, 200, 10);
    Banknote b3(3, 100, 10);
    Banknote b4(4, 50, 10);
    Banknote b5(5, 10, 10);
    Banknote b6(6, 5, 12);
    Banknote b7(7, 1, 1);
    Banknote b8(8, 0.5, 9);
    Banknote b9(9, 0.1, 7);
    Banknote b10(10, 0.05, 10);
    Banknote b11(11, 0.01, 10);

    ser.create(b1);
    ser.create(b2);
    ser.create(b3);
    ser.create(b4);
    ser.create(b5);
    ser.create(b6);
    ser.create(b7);
    ser.create(b8);
    ser.create(b9);
    ser.create(b10);
    ser.create(b11);

    ser.change(565, 565);
    assert(ser.getAll()[0].getNoOccurrences() == 9);
    assert(ser.getAll()[3].getNoOccurrences() == 9);
    assert(ser.getAll()[4].getNoOccurrences() == 9);
    assert(ser.getAll()[5].getNoOccurrences() == 11);
}

