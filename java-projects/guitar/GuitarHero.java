/******************************************************************************
 *  Name:    Michael Zhou
 *  NetID:   myzhou
 *  Precept: P05
 *
 *  Partner Name:    N/A
 *  Partner NetID:   N/A
 *  Partner Precept: N/A
 * 
 *  Description:  Plays up to 37 different guitar strings from a keyboard 
 *                (concert A to concert A). When the user types a key that is 
 *                found within the string that defines the keyboard, a sound 
 *                corresponding to the proper guitar string is played. If a key
 *                with a character not found in the keyboard is pressed, the 
 *                program just ignores it and moves on to the next key pressed.
 *                Multiple keys can be played and heard in superposition if they
 *                are pressed at the same time.
 *
 ******************************************************************************/

public class GuitarHero {

    public static void main(String[] args) {

        // sequence of characters representing the keyboard
        String keyboard = "q2we4r5ty7u8i9op-[=zxdcfvgbnjmk,.;/' ";
        
        // Create base guitar string, for concert A
        double CONCERT_A = 440.0;
        
        // Create an array of GuitarString objects for keyboard characters
        GuitarString[] keys = new GuitarString[keyboard.length()];
        
        // Initializes each GuitarString element of array with their proper
        // string frequencies in relation to base string
        for (int i = 0; i < keyboard.length(); i++) {
            keys[i] = new GuitarString(CONCERT_A * Math.pow(2, (i-24)/12.0));
        }
        
        // the main input loop
        while (true) {

            // check if the user has typed a key, and, if so, process it
            if (StdDraw.hasNextKeyTyped()) {
                
                int note = 0; // index of pressed key if found in keyboard
                
                // the user types this character
                char key = StdDraw.nextKeyTyped();

                // ignores key if not found in keyboard and moves on to next
                if (keyboard.indexOf(key) == -1) {
                    StdDraw.hasNextKeyTyped(); 
                }
                else {
                    // pluck the corresponding string based on key
                    note = keyboard.indexOf(key); 
                    keys[note].pluck();
                }
            }

            // compute the superposition of the current samples
            double sample = 0.0;  // value for initial superposition of samples
            for (int i = 0; i < keyboard.length(); i++) {
                sample += keys[i].sample();
            }

            // send the result to standard audio
            StdAudio.play(sample);

            // advance the simulation of each guitar string by one step
            for (int i = 0; i < keyboard.length(); i++) {
                keys[i].tic();
            }
        }
    }

}
