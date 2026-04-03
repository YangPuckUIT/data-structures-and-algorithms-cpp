#include <iostream>
#include <cstring>

using namespace std;

struct PLACE {
    int hour, min;          // time of visit
    char locName[255];      // location name
    PLACE* next;
};

/* Tạo node mới */
PLACE* createPlace(int hour, int min, const char* name)
{
    PLACE* p = new PLACE;
    p->hour = hour;
    p->min = min;
    strcpy(p->locName, name);
    p->next = NULL;
    return p;
}

/* Thêm node theo thứ tự thời gian tăng dần */
void insertPlace(PLACE*& head, int hour, int min, const char* name)
{
    PLACE* newNode = createPlace(hour, min, name);

    // Chèn đầu danh sách
    if (head == NULL ||
        head->hour > hour ||
       (head->hour == hour && head->min > min))
    {
        newNode->next = head;
        head = newNode;
        return;
    }

    PLACE* current = head;
    while (current->next != NULL &&
          (current->next->hour < hour ||
          (current->next->hour == hour && current->next->min <= min)))
    {
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;
}

/* Hàm kiểm tra có cần báo cáo y tế hay không */
int needMedicalReport(PLACE* visitedPlaces,
                      char* reportLocName,
                      int reportHour,
                      int reportMin)
{
    PLACE* current = visitedPlaces;

    while (current != NULL)
    {
        // Kiểm tra sau thời điểm báo cáo
        if (current->hour > reportHour ||
           (current->hour == reportHour && current->min > reportMin))
        {
            // Kiểm tra đúng địa điểm
            if (strcmp(current->locName, reportLocName) == 0)
            {
                return 1;
            }
        }
        current = current->next;
    }
    return 0;
}

/* In danh sách để kiểm tra */
void printList(PLACE* head)
{
    while (head != NULL)
    {
        cout << head->hour << ":";
        if (head->min < 10) cout << "0";
        cout << head->min << " - " << head->locName << endl;
        head = head->next;
    }
}

int main()
{
    PLACE* visitedPlaces = NULL;

    // Thêm dữ liệu mẫu
    insertPlace(visitedPlaces, 8, 30, "School");
    insertPlace(visitedPlaces, 10, 15, "Market");
    insertPlace(visitedPlaces, 14, 45, "Hospital");
    insertPlace(visitedPlaces, 18, 00, "Mall");

    cout << "Visited places:\n";
    printList(visitedPlaces);

    char reportLocName[] = "Hospital";
    int reportHour = 12;
    int reportMin = 0;

    int result = needMedicalReport(visitedPlaces,
                                   reportLocName,
                                   reportHour,
                                   reportMin);

    if (result == 1)
        cout << "\n=> Need to file medical report\n";
    else
        cout << "\n=> No medical report needed\n";

    return 0;
}
