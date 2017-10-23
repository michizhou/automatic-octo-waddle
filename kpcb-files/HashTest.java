public class HashTest {

    private HashTable<Integer> table;

    // % INITIALIZATION METHODS %
    
    /* Initializes a new hash table of size 10 for every test. It will throw a 
     * java.lang.Exception if something went wrong.
     */
    @Before
    public void setUp() throws Exception
    {
        table = new HashTable<Integer>(10);
    }

    /* Checks that the hash table initializes smoothly.*/
    @Test
    public void testSetup()
    {
        assertNotNull(table);
        assertEquals(table.size(), 10);
        assertEquals(table.elements(), 0);
    }
    
    // GETTER/SETTER METHODS 
 
    /* Checks that the load factor for the hash table is properly calculated.*/
    @Test
    public void testLoad()
    {
        table.set("A", 0);
        
        // we added 1 element, so we want the load factor to be 1/5
        assertEquals(table.elements(), 1);
        assertEquals(table.size(), 10);
        assertEquals(table.load(), .25, .05);
    }
    
    // % GET METHODS %
    
    /* Checks that the function automatically returns NULL if table is empty.*/
    @Test
    public void testGetEmpty() 
    {
        assertEquals(table.getIndexOfKey("Z"), -1);
        assertNull(table.get("Z"));
    }
    
    /* Checks that the function successfully retrieves a value that was inserted
     * directly into the table with no probing required.
     */
    @Test
    public void testGetDirect()
    { 
        table.set("Z", 42);
        
        // 42 should be placed directly at space 0 since this is the initial new space
        assertEquals(table.elements(), 1);
        assertNotEquals(table.getIndexOfKey("Z"), -1);
        assertEquals((int)table.get("Z"), 42);
    }
    
    /* Checks that the function returns NULL for an invalid key.*/
    @Test
    public void testGetInvalidKey()
    { 
        table.set("Z", 42);
        
        assertEquals(table.elements(), 1);
        assertNull(table.get("not Z"));
    }
    
    /* Checks that the function successfully retrieves a value that was inserted
     * into the table using quadratic probing.
     */
    @Test
    public void testGetQuad()
    { 
        // 'Aa' and 'BB' both hash into space 2, 'I' to space 3 triggers quadratic probing.
        table.set("Aa", 42);
        table.set("T", 96);
        table.set("BB", 88);
        
        assertEquals(table.elements(), 3);
        assertEquals((int)table.get("Aa"), 42);
        assertEquals((int)table.get("T"), 96);
        assertEquals((int)table.get("BB"), 88);
    }
    
    /* Checks that the function successfully retrieves a value that was inserted
     * into the table using quadratic probing and linear probing.
     */
    @Test
    public void testGetQuadAndLin()
    { 
        // Leaves index 4 as the only unoccupied space
        table.set("F", 42);
        table.set("G", 96);
        table.set("H", 88);
        table.set("I", 35);
        
        // Tries to insert at index 2, and then will quadratic probe to 3 and 1;
        // since they are filled and we have searched N / 2 elements so now it 
        // will use linear probing to find index 4
        table.set("Aa", 80);
        
        assertEquals(table.elements(), 5);
        assertEquals((int)table.get("F"), 42);
        assertEquals((int)table.get("G"), 96);
        assertEquals((int)table.get("H"), 88);
        assertEquals((int)table.get("I"), 35);
        assertEquals((int)table.get("Aa"), 80);
    }
    
    // % SET METHODS %
    
    /* Checks that no values are added to table when it is at full capacity.*/
    @Test
    public void testSetCapacity()
    {
        for (int i = 0; i <= table.size(); i++)
            table.set(String.valueOf(i), i);
        
        // Fills up table
        assertEquals(table.size(), 10);
        
        // Tries to add another element to full table
        table.set("A", 34);
        
        // Insertion should be unsuccessful
        assertEquals(table.size(), 10);
    }
    
    /* Checks that no duplicate keys are inserted into the table.*/
    @Test
    public void testSetDupliDirect()
    {
        table.set("A", 42);
        table.set("B", 90);
        assertEquals(table.elements(), 2);
        
        // Number of elements should remain the same
        table.set("A", 75);
        assertEquals(table.elements(), 2);
    }
    
    /* Checks that no duplicate keys are inserted into the table (quadratic).*/
    @Test
    public void testSetDupliQuad()
    {
        table.set("Aa", 42);
        table.set("T", 96);
        table.set("BB", 88);
        assertEquals(table.elements(), 3);
        
        // Number of elements should remain the same
        table.set("BB", 9000);
        assertEquals(table.elements(), 3);
    }
    
    /* Checks that no duplicate keys are inserted into the table (linear).*/
    @Test
    public void testSetDupliQuadAndLin()
    {
        // Leaves indices 0 and 4 as only unoccupied spaces
        table.set("G", 55);
        table.set("H", 70);
        table.set("I", 24);

        // Tries to insert at index 2, and then will quadratic probe to 3 and 1;
        // since they are filled and we have searched N / 2 elements so now it 
        // will use linear probing to find index 4
        table.set("Aa", 80);
        assertEquals(table.elements(), 4);
        
        // Number of elements should remain the same
        table.set("Aa", 9000);
        assertEquals(table.elements(), 4);
    }
    
    /* Checks that a value with an empty new space is directly inserted
     * into the hash table without any probing required.
     */
    public void testSetDirect()
    {
        table.set("A", 42);
        
        // 80 should be placed directly at slot 0 since this is the initial new space
        assertEquals(table.elements(), 1);
        assertEquals(table.getIndexOfKey("A"), 0);
    }
    
    // -------------------------------------------------------------------------
    /**
     * Checks that a value with a filled new space is inserted into the hash table
     * using quadratic probing.
     */
    @Test
    public void testSetQuadratic()
    {
        // 'Aa' and 'BB' both hash to slot 2, 'T' to 3
        table.set("Aa", 42);
        table.set("T", 96);
        table.set("BB", 88);
        
        // 88 will try to insert at 2, but the slot is filled so it will
        // look to the next spot using quadratic probing. that's filled as well
        // so the value 88 is inserted at index (2 + 4) % 5 = 1
        assertEquals(table.elements(), 3);
        assertEquals(table.getIndexOfKey("Aa"), 2);
        assertEquals(table.getIndexOfKey("T"), 3);
        assertEquals(table.getIndexOfKey("BB"), 1);
    }
    
    /* Checks that a value with a filled new space is directly inserted
     * into the hash table using quadratic probing and linear probing.
     * For this to happen, the table should have searched N / 2 elements.
     */
    @Test
    public void testSetQuadAndLin()
    {
        // leave index 4 as the only unoccupied space
        table.set("F", 42);
        table.set("G", 96);
        table.set("H", 88);
        table.set("I", 35);
                
        // Tries to insert at index 2, and then will quadratic probe to 3 and 1;
        // since they are filled and we have searched N / 2 elements so now it 
        // will use linear probing to find index 4
        table.set("Aa", 80);
        
        assertEquals(table.elements(), 5);
        assertEquals(table.getIndexOfKey("F"), 0);
        assertEquals(table.getIndexOfKey("G"), 1);
        assertEquals(table.getIndexOfKey("H"), 2);
        assertEquals(table.getIndexOfKey("I"), 3);
        assertEquals(table.getIndexOfKey("Aa"), 4);
    }
    
    // % DELETE METHODS %
    
    /* Checks that the function automatically returns NULL if table is empty.*/
    @Test
    public void testDeleteEmpty()
    {
        assertEquals(table.getIndexOfKey("Z"), -1);
        assertNull(table.delete("Z"));
    }
    
    /* Checks that the function returns NULL for an invalid key.*/
    @Test
    public void testDeleteInvalidKey()
    { 
        table.set("Z", 34);
        
        assertNull(table.delete("not Z"));
        assertEquals(table.elements(), 1);
    }
    
    /* Checks that the function successfully deletes a value that was inserted
     * directly into the table with no probing.
     */
    @Test
    public void testDeleteDirect()
    { 
        table.set("Z", 42);
        assertEquals(table.elements(), 1);
        assertEquals((int)table.get("Z"), 42);
        
        assertEquals((int)table.delete("Z"), 42);
        assertNull(table.get("Z"));
        assertEquals(table.elements(), 0);
    }
    
    /* Checks that a value that was inserted using quadratic probing is
     * successfully deleted.
     */
    @Test
    public void testDeleteQuad()
    {
        table.set("Aa", 42);
        table.set("T", 96);
        table.set("BB", 88);
        assertEquals(table.elements(), 3);
        
        assertEquals((int)table.delete("BB"), 88);
        assertNull(table.get("BB"));
        assertEquals(table.elements(), 2);
    }
    
    /* Checks that a value that was inserted using quadratic probing and
     * linear probing is successfully deleted.
     */
    @Test
    public void testDeleteQuadAndLin()
    {
        // Leaves index 4 as the only unoccupied space
        table.set("F", 42);
        table.set("G", 96);
        table.set("H", 88);
        table.set("I", 35);
        
        // Tries to insert at index 2, and then will quadratic probe to 3 and 1;
        // since they are filled and we have searched N / 2 elements so now it 
        // will use linear probing to find index 4
        table.set("Aa", 80);
        
        assertEquals(table.elements(), 5);
        assertEquals((int)table.delete("Aa"), 80);
        assertNull(table.get("Aa"));
        assertEquals(table.elements(), 4);
    }
    
    /* Tests all methods provided by the hash table and outputs the results out
     * to the terminal screen. (Runnable command-line function)
     */
    public void testAllForResults()
    {
        String[] keys = { "foobar", "rofl", "guhh", "world", "rawr", "glee" };
        int[] values = { 42, 96, 88, 35, 23, 76 };
        
        System.out.println("Table has been initialized with max size 10.");
        
        for (int i = 0; i < keys.length; i++)
        {
            System.out.println("Testing set()... adding value " + values[i] + " for key " + keys[i]);
            table.set(keys[i], values[i]);
        }
        table.printTable();
        
        for (int i = 0; i < keys.length; i++)
            System.out.println("Testing get()... got value " + table.get(keys[i]) + " for key " + keys[i]);
        
        System.out.println("Testing delete()... removing values 96 and 23");
        table.delete("rofl");
        table.delete("rawr");
        table.printTable();
        
        System.out.println("The current load factor of the table is: " + table.load());
    }
}