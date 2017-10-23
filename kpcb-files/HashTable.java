/**
 * A fixed-size HashTable that associates string keys with arbitrary data objects.
 * In accordance with the specification of the problem, only primitive types are used.
 * 
 * Hashing method: The default hash function for keys is provided by Java's built-in
 *                 hash function, hashCode(). [0]*31^(n-1) + s[1]*31^(n-2) + ... + s[n-1]
 *                 
 * Collision resolution: This implementation uses a hybrid approach of quadratic and
 *                       linear probing techniques. The table will use quadratic
 *                       probing up to N / 2 elements, where it then switches over
 *                       to linear probing from the initial index of the hash function.
 * 
 * U is the generic object type for all data elements contained in the table.
 */
public class HashTable<U>
{
    private String[] keys;    // array of String objects designating keys
    private U[] items;        // array of generic type objects for associated items
    
    private int hashHeight;   // maximum size of hash table (number of entries)
    private int numEntries;   // current number of entries in hash table
    
    /*Initializes a new HashTable object with a certain capacity (size) and no entries*/
    public HashTable(int size) {
        if (size < 0) 
            throw new IllegalArgumentException("Please enter a valid table size");
        
        numEntries = 0;
        hashHeight = size;
        keys = new String[size];
        items = (U[]) new Object[size];
    }
    
    /* Inserts a key-value pair into the hash table, based on the String object (key)
     * passed and its associated generic object (value) that are to be inserted.
     * 
     * If the key or value is NULL, it throws an IllegalArgumentException. It will
     * returns true is insertion was successful, false otherwise.
     */
    public boolean set(String key, U value) {
        if (key == null || value == null) 
            throw new IllegalArgumentException("INVALID key or value entered! Try again.");
        
        // If the fixed-size hash table is full, insertion is not allowed
        if (numEntries >= hashHeight)
            return false;
        
        // Forces sign bit to 0 for newSpace so that it always remains positive
        int newSpace = (key.hashCode() & 0x7FFFFFFF) % hashHeight;
        int initialSpace = newSpace, counter = 0;
        
        // Seeks for an an empty spot for entry while watching for duplicate keys
        while (items[newSpace] != null && !keyEquals(key, newSpace))
        {
            if (counter++ <= hashHeight / 2)
            {
                // Uses quadratic probing algorithm through N / 2 elements
                newSpace = (initialSpace + counter * counter) % hashHeight;
            }
            else
            {
                // Starts at initial new space
                if (counter == hashHeight / 2 + 1)
                    newSpace = initialSpace;
                
                // Uses linear probing algorithm from initial hash index
                newSpace = (newSpace + 1) % hashHeight;
            }
        }
        
        // Returns false if a duplicate key is detected
        if (keyEquals(key, newSpace))
            return false;
        
        items[newSpace] = value;
        keys[newSpace] = key;
        numEntries++;
        
        return true;
    }
    
    /* Retrieves the value associated with the specified key in the hash table
     * by searching through hash table for an entry with the specified string
     * associated with the target generic object (key). 
     * 
     * If the key is NULL or invalid it throws IllegalArgumentException. It will
     * return the value associated with the specified key, or NULL if otherwise.
     */
    public U get(String key)
    {
        if (key == null)
            throw new IllegalArgumentException("INVALID key entered! Try again.");
        
        // Returns null with an empty table, since there are no values to retrieve
        if (numEntries == 0)
            return null;
        
        // Find the index of the key, and return NULL if the key doesn't exist
        int properSpace = getKeyIndex(key);
        
        return properSpace != -1 ? items[properSpace] : null;
    }
    
    /* Deletes a value from the table associated with the specified string (key)
     * Returns the generic object deleted from the table, or NULL if not found
     */
    public U delete(String key)
    {
        if (key == null)
            throw new IllegalArgumentException("INVALID key entered! Try again.");
        
        // Returns null with an empty table, since there are no values to delete
        if (numEntries == 0)
            return null;
        
        // Finds the index of the key, and returns NULL if key does not exist
        int properSpace = getKeyIndex(key);
        if (properSpace == -1)
            return null;
        
        U removedEntry = items[properSpace];
        
        // Removes the target element from hash table by deleting memory
        items[properSpace] = null;
        keys[properSpace] = null;
        numEntries--;
        
        return removedEntry;
    }
    

    /* Calculates the proper index necessary for finding/deleting a key value
     * inside the table using both quadratic and linear probing techniques. The 
     * algorithm will use quadratic probing up to N / 2 elements, after which it
     * switches to linear probing from the initial hashed index. Returns index
     * of the key in the table, or -1 if the key does not exist
     */
    public int getKeyIndex(String key)
    {
        int newSpace = (key.hashCode() & 0x7FFFFFFF) % hashHeight;
        int initialSpace = newSpace;
        int positionsChecked = 0, counter = 0;
        
        // Gets the index without searching through the entire table
        while (!keyEquals(key, newSpace))
        {
            if (counter++ <= hashHeight / 2) {
                // Quadratic probing through N / 2 elements
                newSpace = (initialSpace + counter * counter) % hashHeight;
            }
            else
            {
                // Start over at initial new space
                if (counter == hashHeight / 2 + 1)
                    newSpace = initialSpace;
                
                // Prevents an infinite loop if the element doesn't exist
                if (positionsChecked++ == hashHeight)
                    return -1;
                
                // Linear probing from initial hash index
                newSpace = (newSpace + 1) % hashHeight;
            }
        }
        return newSpace;
    }
    

    /* Checks if a string matches to specified string (key) already in the table, 
     * using the index of the key to check the string against. Returns boolean 
     * that indicates whether or not the key is equal to the specified key.
     */
    private boolean keyEquals(String key, int index)
    {
        return key.equals(keys[index]);
    }
    

    /* Gets the load factor of the table indicated by the number of entries
     * in the table divided by the size of the table. Should never return a 
     * value greater than 1.0 since the hash table structure is fixed size.
     */
    public float load()
    {
        return (float)numEntries / hashHeight;
    }
    
    /*Gets and returns the maximum capacity of the table.*/
    public int size() { return hashHeight; }
    
    /* Gets and returns the number of elements currently in the table.*/
    public int elements() { return numEntries; }
    
    /* Prints out all the keys and values in the hash table.
     * TESTING PURPOSES ONLY
     */
    public void printTable()
    {
        for (int i = 0; i < hashHeight; i++)
            System.out.println("<K, V>: [" + keys[i] + ", " + items[i] + "] at index " + i);
    }
    
    public static void main(String[] args) {
        Queue<String> queue = new Queue<String>();
        while (!StdIn.isEmpty()) {
            String item = StdIn.readString();
            if (!item.equals("-")) queue.enqueue(item);
            else if (!queue.isEmpty()) StdOut.print(queue.dequeue() + " ");
        }
        StdOut.println("(" + queue.size() + " left on queue)");
    }
}