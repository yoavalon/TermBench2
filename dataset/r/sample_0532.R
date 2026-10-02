Tokenizer <- R6::R6Class("Tokenizer",
  public = list(
    initialize = function(text) {
      self$text <- text
      self$tokens <- c()
      self$index <- 1
      self$delimiters <- c(' ', '.', ',', '!', '?')
    },
    is_delimiter = function(char) {
      char %in% self$delimiters
    },
    next_token = function() {
      token <- ""
      while (self$index <= nchar(self$text)) {
        char <- substr(self$text, self$index, self$index)
        if (self$is_delimiter(char)) {
          if (nchar(token) > 0) {
            self$tokens <- c(self$tokens, token)
            token <- ""
          }
          self$tokens <- c(self$tokens, char)
        } else {
          token <- paste(token, char, sep="")
        }
        self$index <- self$index + 1
      }
      if (nchar(token) > 0) {
        self$tokens <- c(self$tokens, token)
      }
    }
  )
)

Parser <- R6::R6Class("Parser",
  public = list(
    initialize = function(tokenizer) {
      self$tokenizer <- tokenizer
      self$parsed_data <- list()
    },
    parse = function() {
      self$tokenizer$next_token()
      for (token in self$tokenizer$tokens) {
        if (token %in% names(self$parsed_data)) {
          self$parsed_data[[token]] <- self$parsed_data[[token]] + 1
        } else {
          self$parsed_data[[token]] <- 1
        }
      }
    }
  )
)

DocumentAnalyzer <- R6::R6Class("DocumentAnalyzer",
  public = list(
    initialize = function(text) {
      self$text <- text
      self$tokenizer <- Tokenizer$new(text)
      self$parser <- Parser$new(self$tokenizer)
    },
    analyze = function() {
      self$parser$parse()
      return(self$parser$parsed_data)
    }
  )
)

main <- function() {
  text <- 'Hello, world! This is a test. Hello again.'
  analyzer <- DocumentAnalyzer$new(text)
  while (TRUE) {
    result <- analyzer$analyze()
    print(result)
  }
}

main()