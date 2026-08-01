#include <iostream>
#include "clsUndoRedo.h"
using namespace std;

int main()
{
    clsUndoRedo Text;

    Text.Value = "Tasbih";
    cout << Text.Value << endl;
    Text.Value = "Tasbih Mohammed";
    cout << Text.Value << endl;
    Text.Value = "Tasbih Mohammed :-)";
    cout << Text.Value << endl;

    cout << "\nUndo:\n";
    Text.Undo();
    cout << Text.Value << endl;
    Text.Undo();
    cout << Text.Value << endl;
    Text.Undo();
    cout << Text.Value << endl;   

    cout << "\nRedo:\n";
    Text.Redo();
    cout << Text.Value << endl;
    Text.Redo();
    cout << Text.Value << endl;
    Text.Redo();
    cout << Text.Value << endl;

    return 0;
}