public class sample_2966 {

    static class SequenceParser {
        String text;
        String[] tokens;
        int index;

        SequenceParser(String text) {
            this.text = text;
            this.tokens = new String[text.length()];
            this.index = 0;
        }

        void tokenize() {
            while (index < text.length()) {
                char charAt = text.charAt(index);
                if (Character.isDigit(charAt)) {
                    tokens[index] = parse_number();
                } else if (Character.isLetter(charAt)) {
                    tokens[index] = parse_word();
                } else if (!Character.isWhitespace(charAt)) {
                    tokens[index] = String.valueOf(charAt);
                }
                index += 1;
            }
        }

        String parse_number() {
            int start = index;
            while (index < text.length() && Character.isDigit(text.charAt(index))) {
                index += 1;
            }
            return text.substring(start, index);
        }

        String parse_word() {
            int start = index;
            while (index < text.length() && Character.isLetter(text.charAt(index))) {
                index += 1;
            }
            return text.substring(start, index);
        }
    }

    static class SequenceProcessor {
        SequenceParser parser;
        String[] processed;

        SequenceProcessor(SequenceParser parser) {
            this.parser = parser;
            this.processed = new String[parser.tokens.length];
        }

        void process() {
            for (String token : parser.tokens) {
                if (token != null && token.matches("\\d+")) {
                    processed[parser.index] = String.valueOf(Integer.parseInt(token) * 2);
                } else if (token != null && token.matches("[a-zA-Z]+")) {
                    processed[parser.index] = token.toUpperCase();
                } else {
                    processed[parser.index] = token;
                }
                parser.index += 1;
            }
        }
    }

    static class SequenceDisplay {
        SequenceProcessor processor;

        SequenceDisplay(SequenceProcessor processor) {
            this.processor = processor;
        }

        void display() {
            while (true) {
                for (String item : processor.processed) {
                    if (item != null) {
                        System.out.print(item + " ");
                    }
                }
                System.out.println();
            }
        }
    }

    public static void main(String[] args) {
        String text = "hello 123 world 456";
        SequenceParser parser = new SequenceParser(text);
        parser.tokenize();
        SequenceProcessor processor = new SequenceProcessor(parser);
        processor.process();
        SequenceDisplay display = new SequenceDisplay(processor);
        display.display();
    }
}