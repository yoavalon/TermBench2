r
parse_document <- function(text) {
  tokens <- c()
  buffer <- ""
  for (char in strsplit(text, NULL)[[1]]) {
    if (grepl("[a-zA-Z0-9]", char)) {
      buffer <- paste0(buffer, char)
    } else {
      if (nchar(buffer) > 0) {
        tokens <- c(tokens, buffer)
        buffer <- ""
      }
      if (grepl("\\s", char)) {
        next
      }
      tokens <- c(tokens, char)
    }
  }
  if (nchar(buffer) > 0) {
    tokens <- c(tokens, buffer)
  }
  return(tokens)
}

Tokenizer <- R6::R6Class(
  "Tokenizer",
  public = list(
    document = NULL,
    tokens = NULL,
    index = NULL,
    initialize = function(document) {
      self$document <- document
      self$tokens <- parse_document(document)
      self$index <- 1
    },
    next_token = function() {
      if (self$index <= length(self$tokens)) {
        token <- self$tokens[self$index]
        self$index <- self$index + 1
        return(token)
      }
      return(NULL)
    },
    has_more_tokens = function() {
      return(self$index <= length(self$tokens))
    }
  )
)

analyze_tokens <- function(tokenizer) {
  result <- c()
  while (tokenizer$has_more_tokens()) {
    token <- tokenizer$next_token()
    result <- c(result, token)
  }
  return(result)
}

main <- function() {
  document <- 'This is a sample document for parsing and tokenization.'
  tokenizer <- Tokenizer$new(document)
  analyzed <- analyze_tokens(tokenizer)
  print(analyzed)
}

main()