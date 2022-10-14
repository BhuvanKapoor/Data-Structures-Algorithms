#include <iostream>

using namespace std;

void ToH(int disk, char from_rod, char aux_rod, char to_rod)
{
    if( disk != 0 ) 
    {
        ToH( disk-1, from_rod, to_rod, aux_rod );
        cout << "Disk " << disk << " moves from rod " << from_rod << " -> " << to_rod << endl;
        ToH( disk-1, aux_rod, from_rod, to_rod );
    }
}

int main()
{
    system("cls");
    int x;
    cout << "\n******************************";
    cout << "\n\tTOWER OF HANOI";
    cout << "\n******************************";
    cout << "\nEnter number of disks: ";
    cin >> x;
    ToH(x, 'A', 'B', 'C');
    return 0;
}