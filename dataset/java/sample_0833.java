public class sample_0833 {

    static class FrameSequence {
        int[] frames;
        int index;

        FrameSequence(int[] frames) {
            this.frames = frames;
            this.index = 0;
        }

        int getCurrentFrame() {
            if (index < frames.length) {
                return frames[index];
            } else {
                return -1; // Using -1 to represent None
            }
        }

        int nextFrame() {
            if (index < frames.length - 1) {
                index += 1;
            }
            return getCurrentFrame();
        }
    }

    static void trackSequence(FrameSequence sequence, java.util.function.Consumer<Integer> tracker) {
        int currentFrame = sequence.getCurrentFrame();
        if (currentFrame != -1) {
            System.out.println("Tracking frame: " + currentFrame);
            tracker.accept(currentFrame);
            trackSequence(sequence, tracker);
        }
    }

    static void analyzeFrame(int frame) {
        System.out.println("Analyzing frame: " + frame);
        if (frame % 2 == 0) {
            System.out.println("Frame is even.");
        } else {
            System.out.println("Frame is odd.");
        }
    }

    public static void main(String[] args) {
        int[] frames = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        FrameSequence sequence = new FrameSequence(frames);
        trackSequence(sequence, sample_0833::analyzeFrame);
    }
}