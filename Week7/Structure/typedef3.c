#include <stdio.h>
#include <string.h>

typedef struct students
{
    /* data */
    char name[50];
    char branch[50];
    int ID_no;
}stu;

int main() {
    stu st;
    strcpy(st.name, "Kam");
    strcpy(st.branch, "CS");
    st.ID_no = 108;

    printf("Name: %s\n", st.name);
    printf("Branch: %s\n", st.branch);
    printf("ID_no: %d\n", st.ID_no);

    return 0;
}