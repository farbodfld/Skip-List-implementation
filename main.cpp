#include <iostream>
#include <limits>
#include <ctime>

using namespace std;

struct Node {
    int data;
    int counter;
    Node **nextNodes;

    Node(int data) {
        this->data = data;
        nextNodes = new Node *[10];
        counter = 1;
    }
};

class SkipList {
private:
    Node *head = new Node(std::numeric_limits<int>::min());
    int level = 0;

protected:
    int makingRandomLevel() {
        for (int i = 0; i < 10; i++)
            if (rand() % 4 != 0)
                return i;
        return 0;
    }

public:
    void Insert(int element) {
        Node *current = head;

        Node *helping[10];
        for (int i = 0; i < 10; i++)
            helping[i] = nullptr;

        /** current ro harekat midim ta be node ghablie element beresim
        * va dar hamin hein tamame node haro too helping mirizim
        * va be ye level payintare Skiplist mirim.
        **/
        for (int i = 9; i >= 0; i--) {
            while (current->nextNodes[i] && current->nextNodes[i]->data < element)
                current = current->nextNodes[i];
            helping[i] = current;
        }
        /**be levele 0 residim va bayad current ro be jayi eshare bedim ke
        * gharare element dar anja insert shavad.
        **/
        current = current->nextNodes[0];

        /** age sharte zir bargharar bashe yani bayad element ro
        * beine helping[0] va node e current gharar bedim.
        **/
        if (current == nullptr || current->data != element) {

            /** ye levele random baraye nodesh misazim. **/
            int newLevel = makingRandomLevel();

            /** age sharte zir bargharar bashe bayad element ke jadid ezafe shode ro
            * head gharar bedim va level SkipList ro ham update konim.
            **/
            if (newLevel > this->level) {
                for (int i = this->level + 1; i <= newLevel; i++)
                    helping[i] = head;
                this->level = newLevel;
            }

            /** ye node baraye element misazim o to SkipList gharar midimesh. **/
            Node *ezafeShavande = new Node(element);
            for (int i = 0; i <= newLevel; i++) {
                ezafeShavande->nextNodes[i] = helping[i]->nextNodes[i];
                helping[i]->nextNodes[i] = ezafeShavande;
            }
        } else if (current->data == element)
            current->counter++;
    }

    void Delete(int element) {
        Node *current = head;

        Node *helping[10];
        for (int i = 0; i < 10; i++)
            helping[i] = nullptr;

        /** az inja .... **/
        for (int i = 9; i >= 0; i--) {
            while (current->nextNodes[i] && current->nextNodes[i]->data < element)
                current = current->nextNodes[i];
            helping[i] = current;
        }
        current = current->nextNodes[0];
        /**ta inja eine method e Insert amal mikonim. **/

        /** agar current hamoon element made nazar bashe: **/
        if (current != nullptr && current->data == element) {
            /**
             * mesle delete ye node az ye linked list amal mikonim
             * yani toosh peimayesh mikonim va harja ke node e badie helping[i]
             * barabar ba current ya hamoon element bood next e helping ro be
             *  next current vasl mikonim ta oon node e beineshun ro free konim.
             **/
            for (int i = 0; i <= level && helping[i]->nextNodes[i] == current; i++)
                helping[i]->nextNodes[i] = current->nextNodes[i];
            free(current);
        } else
            cout << "error" << endl;
    }

    bool Search(int element) {
        Node *current = head;

        /**
         * az bala tarin level shroo be harekat mikonim ta vaghti ke
         * "element" bozorgtar az data e node e badie va ye level be payin miaim.
         **/
        for (int i = level; i >= 0; i--) {
            while (current->nextNodes[i] && current->nextNodes[i]->data < element)
                current = current->nextNodes[i];
        }
        /**
         * vaghti ke be levele 0 residim pointer e current ro
         * yeki be rast mibarim ke hamoon node hast ke bayad baresi konimesh.
         **/
        current = current->nextNodes[0];

        if (current != NULL && current->data == element)
            return true;
        else
            return false;
    }

    void Print() {
        if (head->nextNodes[0] == nullptr) {
            cout << "empty" << endl;
            return;
        }
        Node *printingNode = head->nextNodes[0];
        for (printingNode; printingNode != nullptr; printingNode = printingNode->nextNodes[0])
            for (int i = 0; i < printingNode->counter; i++)
                cout << printingNode->data << " ";
        cout << endl;
    }
};

int main() {
    srand(time(nullptr));
    SkipList skipList;
    string input;
    int element;

    while (cin >> input) {
        if (input == "Insert") {
            cin >> element;
            skipList.Insert(element);
        } else if (input == "Delete") {
            cin >> element;
            skipList.Delete(element);
        } else if (input == "Search") {
            cin >> element;
            if (skipList.Search(element))
                cout << "true" << endl;
            else
                cout << "false" << endl;
        } else if (input == "Print") {
            skipList.Print();
        }
    }
}