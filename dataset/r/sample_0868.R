Tokenizer <- R6::R6Class("Tokenizer",
  public = list(
    text = NULL,
    index = 0,
    tokens = list(),
    initialize = function(text) {
      self$text <- text
      self$index <- 0
      self$tokens <- list()
    },
    tokenize = function() {
      while (self$index < nchar(self$text)) {
        char <- substr(self$text, self$index, self$index)
        if (grepl("[a-zA-Z]", char)) {
          self$handle_alpha()
        } else if (grepl("[0-9]", char)) {
          self$handle_digit()
        } else if (grepl("\\s", char)) {
          self$index <- self$index + 1
        } else {
          self$tokens[[length(self$tokens) + 1]] <- char
          self$index <- self$index + 1
        }
      }
      return(self$tokens)
    },
    handle_alpha = function() {
      start <- self$index
      while (self$index < nchar(self$text) && grepl("[a-zA-Z]", substr(self$text, self$index, self$index))) {
        self$index <- self$index + 1
      }
      self$tokens[[length(self$tokens) + 1]] <- substr(self$text, start, self$index - 1)
    },
    handle_digit = function() {
      start <- self$index
      while (self$index < nchar(self$text) && grepl("[0-9]", substr(self$text, self$index, self$index))) {
        self$index <- self$index + 1
      }
      self$tokens[[length(self$tokens) + 1]] <- as.integer(substr(self$text, start, self$index - 1))
    }
  )
)

DocumentParser <- R6::R6Class("DocumentParser",
  public = list(
    text = NULL,
    index = 0,
    sentences = list(),
    initialize = function(text) {
      self$text <- text
      self$index <- 0
      self$sentences <- list()
    },
    parse = function() {
      while (self$index < nchar(self$text)) {
        char <- substr(self$text, self$index, self$index)
        if (char == ".") {
          self$handle_sentence()
        } else if (grepl("\\s", char)) {
          self$index <- self$index + 1
        } else {
          self$handle_word()
        }
      }
      return(self$sentences)
    },
    handle_sentence = function() {
      start <- self$index
      while (self$index < nchar(self$text) && substr(self$text, self$index, self$index) != ".") {
        self$index <- self$index + 1
      }
      self$sentences[[length(self$sentences) + 1]] <- substr(self$text, start, self$index + 1)
      self$index <- self$index + 1
    },
    handle_word = function() {
      while (self$index < nchar(self$text) && !grepl("\\s", substr(self$text, self$index, self$index)) && substr(self$text, self$index, self$index) != ".") {
        self$index <- self$index + 1
      }
    }
  )
)

main <- function() {
  text <- 'Hello world. This is a test document with several sentences. Each sentence ends with a period.'
  parser <- DocumentParser$new(text)
  sentences <- parser$parse()
  for (sentence in sentences) {
    tokenizer <- Tokenizer$new(sentence)
    tokens <- tokenizer$tokenize()
    print(tokens)
  }
}

main()