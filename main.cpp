#include "Repository/RepoInMemory.h"
#include "Tests/tests.h"
#include "Service/TicketService.h"
#include "UI/Console.h"
#include "Repository/RepoInFile.h"

int main() {
    testAll();
    RepoInMemory repoInMemory;
    RepoInFile repoInFile("test.txt");
    IRepo& iRepo = repoInMemory;
    TicketService ser(iRepo);
    Console con(ser);
    con.runMenu();
    return 0;
}
