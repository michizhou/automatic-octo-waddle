/******************************************************************************
 *  Name:    Michael Zhou
 *  NetID:   myzhou
 *  Precept: P05
 *
 *  Partner Name:    N/A
 *  Partner NetID:   N/A
 *  Partner Precept: N/A
 * 
 *  Description:  Program designed to model a ring buffer that is able to 
 *                changed with the addition of new elements and deletion of 
 *                others in the sequence. Models the medium in which energy 
 *                of sound travels back and forth, determining fundamental
 *                frequency of resulting sound and its harmonics.
 *
 ******************************************************************************/

public class RingBuffer {
    private int n;      // maximum capacity of the ring buffer
    private double[] buf; // buf[i] = ith bit of buffer, buf[0] is leftmost bit
    private int first; // index position of least recently inserted item
    private int last; // index position one beyond that of most recent item
    private int size; // current number of elements in ring buffer

    // creates an empty ring buffer with the specified capacity
    public RingBuffer(int capacity) {
        n = capacity;
        buf = new double[n];
        first = 0; // initializes index position of first item to zero
        size = 0;  // initializes size of ring buffer to zero
        last = 0;  // initializes index position of bit beyond last item to zero
    }

    // return the capacity of this ring buffer
    public int capacity() {
        int arraySize = buf.length;
        return arraySize;
    }

    // return number of items currently in this ring buffer
    public int size() {
        return size;
    }

    // returns true if the ring buffer is currently empty and false if there are
    // items present in the ring buffer
    public boolean isEmpty() {
        if (size == 0)
            return true;
        return false;
    }

    // returns true if the ring buffer is full and false if the number of items
    // has not reached the buffer's capacity
    public boolean isFull() {
        if (size == n) 
            return true;
        return false;
    }

    // adds item x to the end of this ring buffer
    public void enqueue(double x) {
        // prints out custom runtime error message if ring buffer is full
        if (isFull()) {
            throw new RuntimeException("Ring buffer is at full capacity.");
        }
        else {
            buf[last] = x; // inserts item x as last element of ring buffer
            last++;        // increments value of last for next iteration
            if (last == n) // sets value of last to zero through wrap-around
                last = 0;   
            size++;        // increments size of ring buffer
        }
    }

    // deletes and returns the item at the front of this ring buffer
    public double dequeue() {
        // prints out custom runtime error message if ring buffer is empty
        if (isEmpty()) {
            throw new RuntimeException("Ring buffer is currently empty.");
        }
        else {
        double temp = buf[first]; // stores value of item at front of buffer
        first++;                  // increments index of first item in buffer
        if (first == n)      // sets value of first to zero through wrap-around
            first = 0;
        size--;              // decreases size of ring buffer
        return temp;
        }
    }

    // returns the item at the front of this ring buffer
    public double peek() {
        // prints out custom runtime error message if ring buffer is full
        if (isEmpty()) {
            throw new RuntimeException("Ring buffer is currently empty.");
        }
        else {
            return buf[first];
        }
    }

    // unit tests for methods in this class
    public static void main(String[] args) {
        
        // tests for all methods of RingBuffer class for ring buffers whose 
        // capacities are specified by a command-line argument
        int n = Integer.parseInt(args[0]);
        RingBuffer buffer = new RingBuffer(n);  
        for (int i = 1; i <= n; i++) {
            buffer.enqueue(i);
        }
        double t = buffer.dequeue();
        buffer.enqueue(t);
        System.out.println("Size after wrap-around is " + buffer.size());
        while (buffer.size() >= 2) {
            double x = buffer.dequeue();
            double y = buffer.dequeue();
            buffer.enqueue(x + y);
        }
        System.out.println(buffer.peek());
        System.out.println(buffer.capacity());
        
        // tests for isEmpty() and isFull() with an empty ring buffer
        RingBuffer buffer0 = new RingBuffer(4);
        System.out.println(buffer0.isEmpty() + " " + buffer0.isFull());
        
        // tests for enqueue(), peek(), and isEmpty() after first item is added
        buffer0.enqueue(180);
        System.out.println(buffer0.peek());
        System.out.println(buffer0.isEmpty());
        
        // tests for enqueue() for isFull() after ring buffer is filled
        buffer0.enqueue(100);
        buffer0.enqueue(123);
        buffer0.enqueue(280);
        System.out.println(buffer0.isFull());
        
        // tests for wrap-around with calls to dequeue() and enqueue()
        double firstVal = buffer0.dequeue();
        System.out.println(firstVal);
        buffer0.enqueue(150);
        while (buffer0.size() > 0) {
            double nextValue = buffer0.dequeue();
            System.out.println(nextValue);
        }
    }

}
