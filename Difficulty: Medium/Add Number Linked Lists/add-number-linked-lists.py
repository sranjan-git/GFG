#User function Template for python3

class Solution:
    def addTwoLists(self, num1, num2):
        sys.set_int_max_str_digits(1000000)
        f1=''
        f2=''
        temp=num1
        while temp:
            f1+=str(temp.data)
            temp=temp.next
        temp=num2
        while temp:
            f2+=str(temp.data)
            temp=temp.next
        f1=str(int(f1)+int(f2))
        head=None
        temm=head
        for i in f1:
            n=Node(int(i))
            if not head:
                head=n
                temm=head
            else:
                temm.next=n
                temm=temm.next
        return head

#{ 
 # Driver Code Starts
#Initial Template for Python 3


# Node Class
class Node:

    def __init__(self, data):
        self.data = data
        self.next = None


# Linked List Class
class LinkedList:

    def __init__(self):
        self.head = None
        self.tail = None

    # creates a new node with given value and appends it at the end of the linked list
    def insert(self, val):
        if self.head is None:
            self.head = Node(val)
            self.tail = self.head
        else:
            self.tail.next = Node(val)
            self.tail = self.tail.next


# prints the elements of linked list starting with head
def printList(n):
    while n:
        print(n.data, end=' ')
        n = n.next
    print()


if __name__ == '__main__':
    for _ in range(int(input())):

        arr1 = (int(x) for x in input().split())
        num1 = LinkedList()
        for i in arr1:
            num1.insert(i)

        arr2 = (int(x) for x in input().split())
        num2 = LinkedList()
        for i in arr2:
            num2.insert(i)

        res = Solution().addTwoLists(num1.head, num2.head)
        printList(res)
        print("~")

# } Driver Code Ends