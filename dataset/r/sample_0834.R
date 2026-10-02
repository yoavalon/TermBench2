Tokenizer <- R6::R6Class("Tokenizer",
  public = list(
    text = NULL,
    index = 0,
    initialize = function(text) {
      self$text <- text
      self$index <- 0
    },
    tokenize = function() {
      tokens <- list()
      while (self$index < nchar(self$text)) {
        if (grepl("[a-zA-Z]", substr(self$text, self$index + 1, self$index + 1))) {
          token <- self$read_alpha()
          tokens[[length(tokens) + 1]] <- token
        } else if (grepl("\\s", substr(self$text, self$index + 1, self$index + 1))) {
          self$skip_space()
        } else {
          self$index <- self$index + 1
        }
      }
      return(tokens)
    },
    read_alpha = function() {
      start <- self$index
      while (self$index < nchar(self$text) && grepl("[a-zA-Z]", substr(self$text, self$index + 1, self$index + 1))) {
        self$index <- self$index + 1
      }
      return(substr(self$text, start + 1, self$index))
    },
    skip_space = function() {
      while (self$index < nchar(self$text) && grepl("\\s", substr(self$text, self$index + 1, self$index + 1))) {
        self$index <- self$index + 1
      }
    }
  )
)

Vectorizer <- R6::R6Class("Vectorizer",
  public = list(
    tokens = NULL,
    vector = list(),
    initialize = function(tokens) {
      self$tokens <- tokens
      self$vector <- list()
    },
    vectorize = function() {
      for (token in self$tokens) {
        self$update_vector(token)
      }
      return(self$vector)
    },
    update_vector = function(token) {
      if (token %in% names(self$vector)) {
        self$vector[[token]] <- self$vector[[token]] + 1
      } else {
        self$vector[[token]] <- 1
      }
    }
  )
)

main <- function() {
  text <- 'This is a sample text for vectorization.'
  tokenizer <- Tokenizer$new(text)
  tokens <- tokenizer$tokenize()
  vectorizer <- Vectorizer$new(tokens)
  vector <- vectorizer$vectorize()
  print(vector)
}

main()