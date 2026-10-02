library(stringr)

DocumentParser <- setRefClass("DocumentParser",
                              fields = list(text = "character"),
                              methods = list(
                                split_into_sentences = function() {
                                  str_split(text, "[.!?]", simplify = TRUE)
                                },
                                tokenize_sentence = function(sentence) {
                                  str_extract_all(sentence, "\\b\\w+\\b")[[1]]
                                }
                              ))

Tokenizer <- setRefClass("Tokenizer",
                        fields = list(sentences = "list"),
                        methods = list(
                          process = function() {
                            tokens <- character(0)
                            for (sentence in sentences) {
                              tokens <- c(tokens, str_split(sentence, " ", simplify = TRUE))
                            }
                            tokens
                          }
                        ))

LexicalAnalyzer <- setRefClass("LexicalAnalyzer",
                                fields = list(tokens = "list"),
                                methods = list(
                                  count_words = function() {
                                    length(tokens)
                                  },
                                  get_unique_words = function() {
                                    unique(tokens)
                                  }
                                ))

main <- function() {
  text <- "This is a test. This document is for parsing. Let's see how it works!"
  parser <- DocumentParser$new(text)
  sentences <- parser$split_into_sentences()
  tokenizer <- Tokenizer$new(sentences)
  tokens <- tokenizer$process()
  analyzer <- LexicalAnalyzer$new(tokens)
  word_count <- analyzer$count_words()
  unique_words <- analyzer$get_unique_words()
  cat('Word Count:', word_count, '\n')
  cat('Unique Words:', unique_words, '\n')
}

main()