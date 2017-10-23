 /*****************************************************************************
 *  Name: Michael Zhou
 *  NetID: myzhou
 *  Precept: P05
*
 *  Partner Name:    N/A
 *  Partner NetID:   N/A
 *  Partner Precept: N/A
 *
 *  Description: LFSR client that can encrypt and decrypt certain pictures by
 *               implementing a transform function along with the main function.
 *               Takes three command-line arguments: the name of the image file,
 *               a binary password in the form of the initial LFSR seed, and an
 *               integer that specifies the LFSR tap position. The transform() 
 *               method takes a Picture and an LFSR as arguments and returns a 
 *               new Picture object that results from transforming a copy of the
 *               original argument image using the LFSR. This is done with the 
 *               following scheme: for each pixel of (col, row), in column-major
 *               order (going down pixels of a column before moving on to next 
 *               column), extract red, green, and blue components of the color.
 *               Then, it will xor each color component with a newly-generated
 *               8-bit integer before creating a new Color object using the 
 *               results of the xor operations as the new color components. The
 *               pixel will be set to that color in the new picture. Finally, 
 *               the transformed picture will be displayed on the screen.
 * 
 *****************************************************************************/

import java.awt.Color;

public class PhotoMagic {
          
   // Returns a transformed copy of the specified picture, using the specified LFSR.
    public static Picture transform(Picture picture, LFSR lfsr) {
        
        Picture newPicture = new Picture(picture); // copy of specified picture
        
        for (int col = 0; col < picture.width(); col++) {
            for (int row = 0; row < picture.height(); row++) {
                Color original = newPicture.get(col, row); // original pixel color
                int red = original.getRed();   // red value of pixel color
                int green = original.getGreen();   // green value of pixel color
                int blue = original.getBlue();   // blue value of pixel color
                
                // Performs exclusive-or operations between RGB values of pixel 
                // color and 8-bit integers generated from specified LFSR
                int newR = red ^ lfsr.generate(8);   // new red value of pixel
                int newG = green ^ lfsr.generate(8); // new green value of pixel
                int newB = blue ^ lfsr.generate(8);  // new blue value of pixel
                Color newHue = new Color(newR, newG, newB); // new pixel color
                newPicture.set(col, row, newHue); 
            }
        }
        return newPicture;
    }

   // Takes the name of an image file and a description of an LFSR as command-line 
   // arguments; displays a copy of the image that is "encrypted" using the LFSR.
    public static void main(String[] args) {
       
        String filename = args[0];   // name of image file 
        LFSR seq0 = new LFSR(args[1], Integer.parseInt(args[2])); // LFSR sequence
        Picture image = new Picture(filename);   // actual data for the image
        Picture magicPhoto = transform(image, seq0); // copy of "encrypted" image
        
        magicPhoto.show();   // displays "encrypted" image on screen
    }
}