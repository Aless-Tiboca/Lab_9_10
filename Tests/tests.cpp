//
// Created by alext on 21/04/2022.
//

#include <cassert>
#include "tests.h"
#include "../Domain/Ticket.h"
#include "../Repository/RepoInMemory.h"
#include "../Repository/RepoInFile.h"
#include "../Service/TicketService.h"

void testAll() {
    testTicket();
    testRepoInMemory();
    testRepoInFile();
    testService();
}

void testTicket() {
    testTicketGet();
    testTicketSet();
}

void testTicketGet() {
    Ticket ticket("12", "Luni", "CJ-SB", 12);
    assert(ticket.getCod() == "CJ-SB");
    assert(ticket.getId() == "12");
    assert(ticket.getPret() == 12);
    assert(ticket.getZiua() == "Luni");
}

void testTicketSet() {
    Ticket ticket("1");
    ticket.setCod("CJ-SB");
    ticket.setPret(12);
    ticket.setZiua("Luni");
    assert(ticket.getCod() == "CJ-SB");
    assert(ticket.getId() == "1");
    assert(ticket.getPret() == 12);
    assert(ticket.getZiua() == "Luni");
}

void testRepoInMemoryAdd() {
    RepoInMemory repoInMemory;
    Ticket ticket("12", "Luni", "CJ-SB", 12);
    Ticket ticket1("123", "Marti", "cdd", 0);
    repoInMemory.create(ticket);
    repoInMemory.create(ticket1);
    assert(repoInMemory.getAll().size() == 2);
    assert(repoInMemory.getAll()[0] == ticket);
}

void testRepoInMemory() {
    testRepoInMemoryAdd();
    testRepoInMemoryGetAll();
    testRepoInMemoryDelete();
    testRepoInMemoryUpdate();
}

void testRepoInMemoryGetAll() {
    RepoInMemory repoInMemory;
    Ticket ticket("12", "Luni", "CJ-SB", 12);
    Ticket ticket1("123");
    repoInMemory.create(ticket);
    repoInMemory.create(ticket1);
    assert(repoInMemory.getAll().size() == 2);
    assert(repoInMemory.getAll()[0] == ticket);
}

void testRepoInMemoryUpdate() {
    RepoInMemory repoInMemory;
    Ticket ticket("12", "Luni", "CJ-SB", 12);
    Ticket ticket1("123");
    repoInMemory.create(ticket);
    repoInMemory.create(ticket1);
    repoInMemory.update("12", Ticket("12", "Marti", "FFF", 10));
    assert(repoInMemory.getAll()[0].getCod() == "FFF");
    assert(repoInMemory.getAll()[0].getId() == "12");
    assert(repoInMemory.getAll()[0].getPret() == 10);
    assert(repoInMemory.getAll()[0].getZiua() == "Marti");
}

void testRepoInMemoryDelete() {
    RepoInMemory repoInMemory;
    Ticket ticket("12", "Luni", "CJ-SB", 12);
    Ticket ticket1("123");
    repoInMemory.create(ticket);
    repoInMemory.create(ticket1);
    assert(repoInMemory.getAll().size() == 2);
    repoInMemory.deleteTicket("12");
    assert(repoInMemory.getAll().size() == 1);
}

void testRepoInFile() {
    testRepoInFileAdd();
    testRepoInFileGetAll();
    testRepoInFileUpdate();
    testRepoInFileDelete();
}

void testRepoInFileAdd() {
    RepoInFile repoInFile("runTest.txt");
    Ticket ticket("12", "Luni", "CJ-SB", 12);
    Ticket ticket1("123", "Marti", "ds", 10);
    repoInFile.create(ticket);
    repoInFile.create(ticket1);
    assert(repoInFile.getAll().size() == 2);
    repoInFile.clearFile();
}

void testRepoInFileGetAll() {
    RepoInFile repoInFile("runTest.txt");
    Ticket ticket("12", "Luni", "CJ-SB", 12);
    Ticket ticket1("123", "Marti", "ds", 10);
    repoInFile.create(ticket);
    repoInFile.create(ticket1);
    assert(repoInFile.getAll().size() == 2);
    repoInFile.clearFile();
}

void testRepoInFileDelete() {
    RepoInFile repoInFile("runTest.txt");
    Ticket ticket("12", "Luni", "CJ-SB", 12);
    Ticket ticket1("123", "Marti", "ds", 10);
    repoInFile.create(ticket);
    repoInFile.create(ticket1);
    repoInFile.deleteTicket("12");
    assert(repoInFile.getAll().size() == 1);
    repoInFile.deleteTicket("123");
    assert(repoInFile.getAll().empty());
}

void testRepoInFileUpdate() {
    RepoInFile repoInFile("runTest.txt");
    Ticket ticket("12", "Luni", "CJ-SB", 12);
    Ticket ticket1("123", "Marti", "ds", 10);
    repoInFile.create(ticket);
    repoInFile.create(ticket1);
    repoInFile.update("12", Ticket("12", "Marti", "FFF", 10));
    assert(repoInFile.getAll()[0].getCod() == "FFF");
    assert(repoInFile.getAll()[0].getId() == "12");
    assert(repoInFile.getAll()[0].getPret() == 10);
    assert(repoInFile.getAll()[0].getZiua() == "Marti");
    repoInFile.clearFile();
}

void testService() {
    testServiceAdd();
    testServiceUpdate();
    testServiceDelete();
    testServiceSumFromADay();
}

void testServiceAdd() {
    RepoInMemory repoInMemory;
    TicketService ser(repoInMemory);
    Ticket ticket("12", "Luni", "CJ-SB", 12);
    Ticket ticket1("123", "Marti", "ds", 10);
    ser.create(ticket);
    ser.create(ticket1);
    assert(ser.getAll().size() == 2);
}

void testServiceSumFromADay() {
    RepoInMemory repoInMemory;
    TicketService ser(repoInMemory);
    Ticket ticket("12", "Luni", "CJ-SB", 12);
    Ticket ticket1("123", "Marti", "ds", 10);
    ser.create(ticket);
    ser.create(ticket1);
    ser.create(Ticket("3", "Luni", "df",10));
    assert(ser.getSumOfTicketsFromADay("Luni")==22);
}

void testServiceDelete() {
    RepoInMemory repoInMemory;
    TicketService ser(repoInMemory);
    Ticket ticket("12", "Luni", "CJ-SB", 12);
    Ticket ticket1("123", "Marti", "ds", 10);
    ser.create(ticket);
    ser.create(ticket1);
    ser.deleteTicket("12");
    assert(ser.getAll().size() == 1);
    ser.deleteTicket("123");
}

void testServiceUpdate() {
    RepoInMemory repoInMemory;
    TicketService ser(repoInMemory);
    Ticket ticket("12", "Luni", "CJ-SB", 12);
    Ticket ticket1("123", "Marti", "ds", 10);
    ser.create(ticket);
    ser.create(ticket1);
    ser.update("12", Ticket("12", "Marti", "FFF", 10));
    assert(ser.getAll()[0].getCod() == "FFF");
    assert(ser.getAll()[0].getId() == "12");
    assert(ser.getAll()[0].getPret() == 10);
    assert(ser.getAll()[0].getZiua() == "Marti");
}
