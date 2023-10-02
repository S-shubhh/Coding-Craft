#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_PARTY 10
struct Party {
    char name[30];
    int votes;
};
// Fucntion To Display Party List 
void ListOfParties(struct Party parties[], int TotalParty)
{
    printf("Party List: \n");
    for(int i =0 ; i < TotalParty ; i++)
    {
        printf("%d. %s\n", i+1, parties[i].name);
    }
}

//  Fucntion for Voting
void chooseCandidate(struct Party parties[], int TotalParty, int choice)
{
    //  checks if the choice is within valid bounds (between 1 and numCandidates)
    if(choice >= 1 && choice <= TotalParty)
    {
        parties[choice - 1].votes++;
        printf("You have successfully choosed your candidate for %s.\n", parties[choice - 1].name);
    }
     else {
        printf("Invalid choice. Please select a valid party.\n");
    }
}

int findWinningCandidate(struct Party parties[], int TotalParty )
{
    //  initializes leadingPartyIndex to 0, assuming the first Party is initially the leading Party.
    int leadingPartyIndex = 0;
    for(int i =1; i < TotalParty; i++)
    {
        if(parties[i].votes > parties[leadingPartyIndex].votes)
        {
            leadingPartyIndex = i ;
        }
    }
    return leadingPartyIndex;
}

int main()
{
    int totalParty;
    struct Party parties[MAX_PARTY];
    
    printf("Online Voting System \n");
    
    printf("Enter the number of parties (up to %d): ", MAX_PARTY);
    scanf("%d", &totalParty);

    if (totalParty < 1 || totalParty > MAX_PARTY) {
        printf("Invalid number of Party.\n");
        return 1;
    }
    
    for (int i = 0; i < totalParty; i++) {
        printf("Enter the name of Party %d: ", i + 1);
        scanf(" %[^\n]", parties[i].name);
        parties[i].votes = 0;
    }
    int choice;
    while (1) {
        printf("\nMenu:\n");
        printf("1. Display Party\n");
        printf("2. Choose Candidate\n");
        printf("3.  Wining Party\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                ListOfParties(parties, totalParty);
                break;
            case 2:
                ListOfParties(parties, totalParty);
                printf("Enter the number of the candidate you want to vote for: ");
                scanf("%d", &choice);
                chooseCandidate(parties, totalParty, choice);
                break;
            case 3:
                if (totalParty > 0) {
                    int leadingPartyIndex = findWinningCandidate(parties, totalParty);
                    printf("Leading Candidate: %s with %d votes.\n", parties[leadingPartyIndex].name, parties[leadingPartyIndex].votes);
                } else {
                    printf("No Party available.\n");
                }
                break;
            case 4:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice. Please select a valid option.\n");
        }
    }

    return 0;
}