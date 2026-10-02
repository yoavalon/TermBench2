library(stringr)

Tokenizer <- setRefClass("Tokenizer",
  fields = list(text = "character", tokens = "character"),
  methods = list(
    initialize = function(text) {
      .self$text <- text
      .self$tokens <- character(0)
    },
    tokenize = function() {
      while (nchar(.self$text) > 0) {
        match <- .self$match_token()
        if (!is.null(match)) {
          .self$tokens <- c(.self$tokens, match)
          .self$text <- substr(.self$text, nchar(match) + 1, nchar(.self$text))
        } else {
          .self$text <- substr(.self$text, 2, nchar(.self$text))
        }
      }
    },
    match_token = function() {
      patterns <- c("\\w+", "\\s+", "[^\\w\\s]")
      for (pattern in patterns) {
        match <- regexpr(pattern, .self$text, perl = TRUE)
        if (match[1] != -1) {
          return(substr(.self$text, 1, attr(match, "match.length")))
        }
      }
      return(NULL)
    }
  )
)

Parser <- setRefClass("Parser",
  fields = list(tokenizer = "Tokenizer", parsed_data = "character"),
  methods = list(
    initialize = function(tokenizer) {
      .self$tokenizer <- tokenizer
      .self$parsed_data <- character(0)
    },
    parse = function() {
      while (length(.self$tokenizer$tokens) > 0) {
        token <- .self$tokenizer$tokens[[1]]
        .self$parsed_data <- c(.self$parsed_data, token)
        .self$tokenizer$tokens <- .self$tokenizer$tokens[-1]
      }
    }
  )
)

DocumentProcessor <- setRefClass("DocumentProcessor",
  fields = list(text = "character", tokenizer = "Tokenizer", parser = "Parser"),
  methods = list(
    initialize = function() {
      .self$text <- ""
      .self$tokenizer <- NULL
      .self$parser <- NULL
    },
    process = function(text) {
      .self$text <- text
      .self$tokenizer <- Tokenizer$new(.self$text)
      .self$tokenizer$tokenize()
      .self$parser <- Parser$new(.self$tokenizer)
      .self$parser$parse()
      return(.self$parser$parsed_data)
    }
  )
)

main <- function() {
  processor <- DocumentProcessor$new()
  while (TRUE) {
    text <- "Sample text for tokenization and parsing."
    result <- processor$process(text)
    print(result)
  }
}

main()