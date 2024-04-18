#include <iostream>

struct Node
{
    int data;
    Node *next;
    Node() : data(0), next(nullptr)
    {
    }
    Node(int data) : data(data), next(nullptr)
    {
    }
    ~Node()
    {
    }
    friend std::ostream &operator<<(std::ostream &stream, Node &node)
    {

        std::cout << node.data;
        return stream;
    }
};

class LinkedList {
    public:
    LinkedList() : head(nullptr)
    {
    }
    ~LinkedList()
    {
        dispose();
    }
    int Length()
    {
        int count = 0;
        Node *node = head;
        while (node != nullptr)
        {
            count++;
            node = node->next;
        }
        return count;
    }

    bool IsEmpty()
    {
        return head == nullptr;
    };

    void PushHead(int data)
    {
        Node *node = new Node(data);
        InsertNode(0, node);
    }
    void Insert(int index, int data)
    {
        Node *node = new Node(data);
        InsertNode(index, node);
    }
    void PushTail(int data)
    {
        Node *node = new Node(data);
        InsertNode(Length(), node);
    }

    int PopHead()
    {
        return PopData(ExtractNode(0));
    }

    int Extract(int index)
    {
        return PopData(ExtractNode(index));
    };
    int PopTail()
    {
        return PopData(ExtractNode(Length() - 1));
    }

    int Data(int index)
    {
        if (!IndexValid(index) || (Length() - 1 < index))
        {
            return 0;
        }

        Node *current = head;
        while (index > 0)
        {
            current = current->next;
            index = index - 1;
        }
        return current->data;
    }
    void swap(int ia, int ib)
    {
        if (!IndexValid(ia) || !IndexValid(ib) || ia == ib)
        {
            return;
        }

        if (ia > ib)
        {
            int tmp = ib;
            ib = ia;
            ia = tmp;
        }
        Node *nodeB = ExtractNode(ib);
        Node *nodeA = ExtractNode(ia);

        if (nodeA == nullptr || nodeB == nullptr)
        {
            return;
        }

        InsertNode(ia, nodeB);
        InsertNode(ib, nodeA);
    }

    void sort()
    {
        for (int i = Length() - 1; i >= 0; i--)
        {
            for (int j = 0; j < i; j++)
            {
                if (Data(j) > Data(j + 1))
                {
                    swap(j, j + 1);
                }
            }
        }
    }

    friend std::ostream &operator<<(std::ostream &stream, LinkedList &list)
    {
        Node *current = list.head;
        while (current != nullptr)
        {
            stream << *current << " ";
            current = current->next;
        }
        return stream;
    };

    private:
    // Как рыба гниет с головы, так и список тоже очищаем с головы
    //(C) защищено авторским правом бай альмаков илья евгеньевич
    void dispose()
    {
        while (head != nullptr)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
    }

    int PopData(Node *node)
    {
        if (node == nullptr)
        {
            return 0;
        }
        int res = node->data;
        delete node;
        return res;
    }
    void InsertNode(int index, Node *node)
    {
        if (!IndexValid(index))
        {
            return;
        }
        if (index == 0)
        {
            node->next = head;
            head = node;
        }
        else if (index == Length())
        {
            Node *current = head;
            while (current->next != nullptr)
            {
                current = current->next;
            }
            current->next = node;
        }
        else if (index < Length())
        {
            Node *current = head;
            for (int i = 0; i < index - 1; i++)
            {
                current = current->next;
            }
            node->next = current->next;
            current->next = node;
        }
    }

    Node *ExtractNode(int index)
    {
        if (!IndexValid(index))
        {
            return nullptr;
        }
        if (index == 0)
        {
            Node *temp = head;
            head = head->next;
            return temp;
        }
        if (index == Length() - 1)
        {
            Node *current = head;
            while (current->next->next != nullptr)
            {
                current = current->next;
            }
            Node *temp = current->next;
            current->next = nullptr;
            return temp;
        }
        if (index < Length())
        {
            Node *current = head;
            for (int i = 0; i < index - 1; i++)
            {
                current = current->next;
            }
            Node *temp = current->next;
            current->next = current->next->next;
            return temp;
        }
        return nullptr;
    }
    bool IndexValid(int index)
    {
        if (index < 0 || index > Length())
        {
            return false;
        }
        return true;
    }
    Node *head;
};

int main(int argc, char *argv[])
{
    LinkedList list;
    std::cout << list << std::endl;
    list.PushHead(1);
    std::cout << list << std::endl;
    list.PushTail(3);
    std::cout << list << std::endl;
    list.Insert(1, 2);
    std::cout << list << std::endl;
    list.Insert(3, 4);
    std::cout << list << std::endl << std::endl;
    std::cout << list << std::endl;
    std::cout << list.PopHead() << " ";
    std::cout << list.Extract(1) << " ";
    std::cout << list.PopTail() << " ";
    std::cout << list.Extract(0) << std::endl;
    std::cout << list << std::endl << std::endl;

    list.PushHead(3);
    list.PushHead(4);
    list.PushHead(1);
    list.PushHead(2);
    list.PushHead(7);
    list.PushHead(5);
    list.PushHead(8);
    list.PushHead(6);
    std::cout << list << std::endl;
    list.sort();
    std::cout << list << std::endl;
    return EXIT_SUCCESS;
}
