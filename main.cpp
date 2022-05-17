#include "Tests/tests.h"
#include "Service/TicketService.h"
#include "UI/Console.h"
#include "Repository/IRepo.h"
#include "Repository/RepoInMemory.h"
#include "Repository/RepoInFile.h"

int main() {
    testAll();
    RepoInMemory<Ticket> repoInMemory1;
    RepoInMemory<Banknote> repoInMemory2;
    RepoInFile<Ticket> repoInFile1("ticket.txt");
    RepoInFile<Banknote> repoInFile2("banknotes.txt");
    IRepo<Ticket>& iRepo1 = repoInFile1;
    IRepo<Banknote>& iRepo2 = repoInFile2;
    TicketService serT(iRepo1);
    BanknoteService serB(iRepo2);
    Console console(serT, serB);
    console.runMenu();
    return 0;
}
