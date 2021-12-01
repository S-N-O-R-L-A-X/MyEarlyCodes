#include <stdio.h>
#include <stdlib.h>

int main()
{
    int day,month,year;
    scanf("%d %d %d",&day,&month,&year);

    switch(month)
    {
    case 4:case 6:case 9:case 11:
        if(day>=31)
            printf("error");
    break;
    case 2:
        if(day>=30)
            printf("error");
    break;
    default:
    switch(day)
    {
    case 1:
        switch(month)
        {
        case 1:
            printf("1st January %d",year);
            break;
        case 2:
            printf("1st February %d",year);
            break;
        case 3:
            printf("1st March %d",year);
            break;
        case 4:
            printf("1st April %d",year);
            break;
        case 5:
            printf("1st May %d",year);
            break;
        case 6:
            printf("1st June %d",year);
            break;
        case 7:
            printf("1st July %d",year);
            break;
        case 8:
            printf("1st August %d",year);
            break;
        case 9:
            printf("1st September %d",year);
            break;
        case 10:
            printf("1st October %d",year);
            break;
        case 11:
            printf("1st November %d",year);
            break;
        default:
            printf("1st December %d",year);
            break;
        }
    break;
    case 2:
        switch(month)
        {
        case 1:
            printf("2nd January %d",year);
            break;
        case 2:
            printf("2nd February %d",year);
            break;
        case 3:
            printf("2nd March %d",year);
            break;
        case 4:
            printf("2nd April %d",year);
            break;
        case 5:
            printf("2nd May %d",year);
            break;
        case 6:
            printf("2nd June %d",year);
            break;
        case 7:
            printf("2nd July %d",year);
            break;
        case 8:
            printf("2nd August %d",year);
            break;
        case 9:
            printf("2nd September %d",year);
            break;
        case 10:
            printf("2nd October %d",year);
            break;
        case 11:
            printf("2nd November %d",year);
            break;
        default:
            printf("2nd December %d",year);
            break;
        }
    break;
    case 3:
        switch(month)
        {
        case 1:
            printf("3rd January %d",year);
            break;
        case 2:
            printf("3rd February %d",year);
            break;
        case 3:
            printf("3rd March %d",year);
            break;
        case 4:
            printf("3rd April %d",year);
            break;
        case 5:
            printf("3rd May %d",year);
            break;
        case 6:
            printf("3rd June %d",year);
            break;
        case 7:
            printf("3rd July %d",year);
            break;
        case 8:
            printf("3rd August %d",year);
            break;
        case 9:
            printf("3rd September %d",year);
            break;
        case 10:
            printf("3rd October %d",year);
            break;
        case 11:
            printf("3rd November %d",year);
            break;
        default:
            printf("3rd December %d",year);
            break;
        }
    break;
    case 21:
        switch(month)
        {
        case 1:
            printf("21st January %d",year);
            break;
        case 2:
            printf("21st February %d",year);
            break;
        case 3:
            printf("21st March %d",year);
            break;
        case 4:
            printf("21st April %d",year);
            break;
        case 5:
            printf("21st May %d",year);
            break;
        case 6:
            printf("21st June %d",year);
            break;
        case 7:
            printf("21st July %d",year);
            break;
        case 8:
            printf("21st August %d",year);
            break;
        case 9:
            printf("21st September %d",year);
            break;
        case 10:
            printf("21st October %d",year);
            break;
        case 11:
            printf("21st November %d",year);
            break;
        default:
            printf("21st December %d",year);
            break;
        }
    break;
    case 22:
        switch(month)
        {
        case 1:
            printf("22nd January %d",year);
            break;
        case 2:
            printf("22nd February %d",year);
            break;
        case 3:
            printf("22nd March %d",year);
            break;
        case 4:
            printf("22nd April %d",year);
            break;
        case 5:
            printf("22nd May %d",year);
            break;
        case 6:
            printf("22nd June %d",year);
            break;
        case 7:
            printf("22nd July %d",year);
            break;
        case 8:
            printf("22nd August %d",year);
            break;
        case 9:
            printf("22nd September %d",year);
            break;
        case 10:
            printf("22nd October %d",year);
            break;
        case 11:
            printf("22nd November %d",year);
            break;
        default:
            printf("22nd December %d",year);
            break;
        }
    break;
    case 23:
        switch(month)
        {
        case 1:
            printf("23rd January %d",year);
            break;
        case 2:
            printf("23rd February %d",year);
            break;
        case 3:
            printf("23rd March %d",year);
            break;
        case 4:
            printf("23rd April %d",year);
            break;
        case 5:
            printf("23rd May %d",year);
            break;
        case 6:
            printf("23rd June %d",year);
            break;
        case 7:
            printf("23rd July %d",year);
            break;
        case 8:
            printf("23rd August %d",year);
            break;
        case 9:
            printf("23rd September %d",year);
            break;
        case 10:
            printf("23rd October %d",year);
            break;
        case 11:
            printf("23rd November %d",year);
            break;
        default:
            printf("23rd December %d",year);
            break;
        }
    break;
    case 31:
        switch(month)
        {
        case 1:
            printf("31st January %d",year);
            break;
        case 2:
            printf("31st February %d",year);
            break;
        case 3:
            printf("31st March %d",year);
            break;
        case 4:
            printf("31st April %d",year);
            break;
        case 5:
            printf("31st May %d",year);
            break;
        case 6:
            printf("31st June %d",year);
            break;
        case 7:
            printf("31st July %d",year);
            break;
        case 8:
            printf("31st August %d",year);
            break;
        case 9:
            printf("31st September %d",year);
            break;
        case 10:
            printf("31st October %d",year);
            break;
        case 11:
            printf("31st November %d",year);
            break;
        default:
            printf("31st December %d",year);
            break;
        }
    break;
    default:
        switch(month)
        {
        case 1:
            printf("%dth January %d",day,year);
            break;
        case 2:
            printf("%dth February %d",day,year);
            break;
        case 3:
            printf("%dth March %d",day,year);
            break;
        case 4:
            printf("%d April %d",day,year);
            break;
        case 5:
            printf("%d May %d",day,year);
            break;
        case 6:
            printf("%d June %d",day,year);
            break;
        case 7:
            printf("%d July %d",day,year);
            break;
        case 8:
            printf("%d August %d",day,year);
            break;
        case 9:
            printf("%d September %d",day,year);
            break;
        case 10:
            printf("%d October %d",day,year);
            break;
        case 11:
            printf("%d November %d",day,year);
            break;
        default:
            printf("%d December %d",day,year);
            break;
        }
    break;
    }
    }

    return 0;
}
