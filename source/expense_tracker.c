#include "../headers/cointrack.h"

void expenseTracker(int page)
{
    while (1)
    {        
        header("EXPENSE TRACKER");

        int recordCount = getRecordCount();
        printf("\t\tTotal records: %d\n", recordCount);

        if (recordCount > 0)
        {
            FILE *file = readFile("records.dat");

            textYellow();
            printf("\t\t%s\t%s\t\t\t%s\t\t%s", "ID", "DETAILS", "DATE", "AMOUNT");
            textWhite();

            Record record[recordCount];
            fread(record, sizeof(Record), recordCount, file);
            fclose(file);

            for (int i = 0; i < recordCount; i++)
            {
                // if (record[i].userId != curUserId)
                // {
                //     continue;
                // }

                nl;
                hLine_thin();

                stripNewLine(record[i].details);

                int detailsLen = strlen(record[i].details);
                int maxLen = 20;
                int lines = ceil((float) detailsLen / maxLen);
                int center = ((int) ceil(lines / 2.0)) * maxLen;
                int extra = maxLen - detailsLen;
                
                if (detailsLen <= maxLen || center-maxLen == 0)
                {
                    printf("\t\t%d\t", record[i].id);
                }
                else
                {
                    printf("\t\t\t");
                }

                for (int j = 0; j < detailsLen; j++)
                {
                    printf("%c", record[i].details[j]);

                    
                    if (j+1 == center)
                    {
                        printf("\t%02d-%02d-%d", record[i].date.day, record[i].date.month, record[i].date.year);
                        printf("\t%lld", record[i].amount);
                    }
                    if ((j+1) % maxLen == 0 && j != detailsLen-1)
                    {
                        nl;
                        if (detailsLen > maxLen && j+1 == center-maxLen)
                        {
                            printf("\t\t%d\t", record[i].id);
                        }
                        else
                        {
                            printf("\t\t\t");
                        }
                    }
                }
                if (detailsLen < maxLen)
                {
                    while (extra--)
                    {
                        printf(" ");
                    }
                    printf("\t%02d-%02d-%d", record[i].date.day, record[i].date.month, record[i].date.year);
                    printf("\t%lld", record[i].amount);
                }

                // printf("\t\t%d\t", record[i].id);
                // printf("%s\t", record[i].details);
                // printf("%d-%d-%d\t", record[i].date.day, record[i].date.month, record[i].date.year);
                // printf("%lld", record[i].amount);
            }
        }
        else
        {
            printf("\t\tNo records found.\n");
        }
        
        hLine();
        nl;
        
        command("\t<-  ");
        printf("Back");
        nl;
        command("\t +  ");
        printf("Add Record");
        nl;
        command("\t -  ");
        printf("Delete Record");
        
        char command = getch();

        if (command == -32)
        {
            char command = getch();
            if (command == 75)
            {
                return;
            }
            else
            {
                alert("Invalid key!", 1);
            }
        }
        else if (command == '+')
        {
            addRecord();
        }
        else if (command == '-')
        {
            deleteRecord();
        }
        else
        {
            alert("Invalid key!", 1);
        }
    }
}

void addRecord()
{
    nl;
    nl;
    showCursor();
    Record record;

    record.id = genRecordId();
    record.userId = curUserId;

    printf("\t    Enter Record Details\n");
    printf("\t    Expenditure Type: ");
    textYellow();
    fflush(stdin);
    fgets(record.details, 512, stdin);

    int amount;
    textWhite();
    printf("\t    Amount: ");
    textYellow();
    scanf("%lld", &record.amount);
    
    int day, month, year;
    textWhite();
    printf("\t    Day (DD): ");
    textYellow();
    scanf("%d", &day);
    if (day < 1 || day > 31)
    {
        alert("    Invalid day!", 1.5);
        return;
    }
    textWhite();
    printf("\t    Month (MM): ");
    textYellow();
    scanf("%d", &month);
    if (month < 1 || month > 12)
    {
        alert("    Invalid month!", 1.5);
        return;
    }
    textWhite();
    printf("\t    Year (YYYY): ");
    textYellow();
    scanf("%d", &year);
    if (year < 1000 || year > 9999)
    {
        alert("    Invalid year!", 1.5);
        return;
    }

    record.date.day = day;
    record.date.month = month;
    record.date.year = year;
    
    FILE *file = appendFile("records.dat");
    fwrite(&record, sizeof(Record), 1, file);
    fclose(file);
    
}