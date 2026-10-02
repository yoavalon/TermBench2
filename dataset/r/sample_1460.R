DocumentTokenizer <- R6::R6Class("DocumentTokenizer",
  public = list(
    text = NULL,
    tokens = NULL,
    
    initialize = function(text) {
      self$text <- text
      self$tokens <- character(0)
    },
    
    tokenize = function() {
      for (char in strsplit(self$text, NULL)[[1]]) {
        if (grepl("^[a-zA-Z0-9\\s]$", char)) {
          self$tokens <- c(self$tokens, char)
        } else {
          self$tokens <- c(self$tokens, " ")
        }
      }
    },
    
    filter_tokens = function() {
      filtered_tokens <- character(0)
      word <- ""
      for (token in self$tokens) {
        if (grepl("^[a-zA-Z0-9]$", token)) {
          word <- paste(word, token, sep = "")
        } else if (grepl("^\\s$", token) && nchar(word) > 0) {
          filtered_tokens <- c(filtered_tokens, word)
          word <- ""
        }
      }
      if (nchar(word) > 0) {
        filtered_tokens <- c(filtered_tokens, word)
      }
      self$tokens <- filtered_tokens
    }
  )
)

DataMutator <- R6::R6Class("DataMutator",
  public = list(
    tokenizer = NULL,
    tokens = NULL,
    
    initialize = function(tokenizer) {
      self$tokenizer <- tokenizer
    },
    
    mutate = function() {
      self$tokenizer$tokenize()
      self$tokenizer$filter_tokens()
      self$tokens <- self$tokenizer$tokens
    }
  )
)

main <- function() {
  text <- "Hello, world! This is a test."
  tokenizer <- DocumentTokenizer$new(text)
  mutator <- DataMutator$new(tokenizer)
  mutator$mutate()
  print(mutator$tokens)
}

main()