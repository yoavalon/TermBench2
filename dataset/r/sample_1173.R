Tokenizer <- R6::R6Class("Tokenizer",
  public = list(
    text = NULL,
    tokens = NULL,
    pos = NULL,
    initialize = function(text) {
      self$text <- text
      self$tokens <- c()
      self$pos <- 0
    },
    tokenize = function() {
      self$tokens <- c()
      self$pos <- 0
      while (self$pos < nchar(self$text)) {
        self$_read_next_token()
      }
      return(self$tokens)
    },
    _read_next_token = function() {
      while (self$pos < nchar(self$text) && grepl("\\s", substring(self$text, self$pos, self$pos))) {
        self$pos <- self$pos + 1
      }
      if (self$pos == nchar(self$text)) {
        return()
      }
      start <- self$pos
      if (grepl("[A-Za-z]", substring(self$text, self$pos, self$pos))) {
        while (self$pos < nchar(self$text) && grepl("[A-Za-z0-9]", substring(self$text, self$pos, self$pos))) {
          self$pos <- self$pos + 1
        }
        self$tokens <- c(self$tokens, substring(self$text, start, self$pos - 1))
      } else if (grepl("[0-9]", substring(self$text, self$pos, self$pos))) {
        while (self$pos < nchar(self$text) && grepl("[0-9]", substring(self$text, self$pos, self$pos))) {
          self$pos <- self$pos + 1
        }
        self$tokens <- c(self$tokens, substring(self$text, start, self$pos - 1))
      } else {
        self$pos <- self$pos + 1
        self$tokens <- c(self$tokens, substring(self$text, start, self$pos - 1))
      }
    }
  )
)

DocumentParser <- R6::R6Class("DocumentParser",
  public = list(
    text = NULL,
    parser = NULL,
    initialize = function(text) {
      self$text <- text
      self$parser <- Tokenizer$new(self$text)
    },
    parse = function() {
      return(self$parser$tokenize())
    }
  )
)

main <- function() {
  text <- 'This is a sample text for document parsing.'
  parser <- DocumentParser$new(text)
  tokens <- parser$parse()
  print(tokens)
}

main()