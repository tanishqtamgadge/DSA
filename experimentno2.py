class Node:
    def __init__(self, key, value):
        self.key = key
        self.value = value
        self.next = None

class HashTable:
    def __init__(self, size):
        self.size = size
        self.table = [None] * self.size

    def _hash(self, key):
        return hash(key) % self.size

    # Insert a key-value pair (with replacement)
    def insert_with_replacement(self, key, value):
        index = self._hash(key)
        node = self.table[index]
        
        # Check if the key already exists
        while node:
            if node.key == key:
                node.value = value  # Replace the value
                print(f"Key '{key}' updated with value: {value}")
                return
            node = node.next
        
        # If key doesn't exist, add a new node
        new_node = Node(key, value)
        new_node.next = self.table[index]
        self.table[index] = new_node
        print(f"Key '{key}' inserted with value: {value}")

    # Insert a key-value pair (without replacement)
    def insert_without_replacement(self, key, value):
        index = self._hash(key)
        node = self.table[index]
        
        # Check if the key already exists
        while node:
            if node.key == key:
                print(f"Key '{key}' already exists. No replacement made.")
                return  # Do nothing (no replacement)
            node = node.next
        
        # If key doesn't exist, add a new node
        new_node = Node(key, value)
        new_node.next = self.table[index]
        self.table[index] = new_node
        print(f"Key '{key}' inserted with value: {value}")

    # Search for a key in the hash table
    def search(self, key):
        index = self._hash(key)
        node = self.table[index]
        
        while node:
            if node.key == key:
                print(f"Key '{key}' found with value: {node.value}")
                return
            node = node.next
        print(f"Key '{key}' not found!")

    # Delete a key-value pair from the hash table
    def delete(self, key):
        index = self._hash(key)
        node = self.table[index]
        prev = None
        
        while node:
            if node.key == key:
                if prev:
                    prev.next = node.next
                else:
                    self.table[index] = node.next
                print(f"Key '{key}' deleted.")
                return
            prev = node
            node = node.next
        print(f"Key '{key}' not found!")

    # Display the hash table for debugging
    def display(self):
        for i in range(self.size):
            node = self.table[i]
            if node:
                print(f"Index {i}:", end=" ")
                while node:
                    print(f"({node.key}: {node.value})", end=" -> ")
                    node = node.next
                print("None")

def main():
    # Ask the user to define the size of the hash table
    size = int(input("Enter the size of the hash table: "))
    ht = HashTable(size)

    while True:
        # Menu of operations
        print("\nChoose an operation:")
        print("1. Insert with replacement")
        print("2. Insert without replacement")
        print("3. Search for a key")
        print("4. Delete a key")
        print("5. Display hash table")
        print("6. Exit")

        choice = input("Enter your choice (1-6): ")

        if choice == '1':
            key = input("Enter key: ")
            value = input("Enter value: ")
            ht.insert_with_replacement(key, value)

        elif choice == '2':
            key = input("Enter key: ")
            value = input("Enter value: ")
            ht.insert_without_replacement(key, value)

        elif choice == '3':
            key = input("Enter key to search: ")
            ht.search(key)

        elif choice == '4':
            key = input("Enter key to delete: ")
            ht.delete(key)

        elif choice == '5':
            ht.display()

        elif choice == '6':
            print("Exiting program...")
            break

        else:
            print("Invalid choice! Please choose between 1 and 6.")

if __name__ == "__main__":
    main()
