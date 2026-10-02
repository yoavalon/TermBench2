library(stringr)

Tokenizer <- setRefClass("Tokenizer",
  fields = list(
    text = "character",
    tokens = "list"
  ),
  methods = list(
    initialize = function(text) {
      .self$text <- text
      .self$tokens <- list()
      .self$tokenize()
    },
    tokenize = function() {
      pattern <- "\\b\\w+\\b"
      matches <- str_extract_all(.self$text, pattern)[[1]]
      for (match in matches) {
        .self$tokens <- c(.self$tokens, match)
      }
    }
  )
)

SequenceAnalyzer <- setRefClass("SequenceAnalyzer",
  fields = list(
    tokenizer = "Tokenizer",
    sequence = "list"
  ),
  methods = list(
    initialize = function(tokenizer) {
      .self$tokenizer <- tokenizer
      .self$sequence <- list()
      .self$analyze()
    },
    analyze = function() {
      for (token in .self$tokenizer$tokens) {
        if (grepl("^\\d+$", token)) {
          .self$sequence <- c(.self$sequence, as.integer(token))
        } else {
          .self$sequence <- c(.self$sequence, NA)
        }
      }
    }
  )
)

SequenceGenerator <- setRefClass("SequenceGenerator",
  fields = list(
    analyzer = "SequenceAnalyzer",
    current_value = "numeric"
  ),
  methods = list(
    initialize = function(analyzer) {
      .self$analyzer <- analyzer
      .self$current_value <- 0
    },
    generate = function() {
      while (TRUE) {
        .self$current_value <- .self$current_value + 1
        if (!is.na(match(.self$current_value, .self$analyzer$sequence))) {
          .self$current_value <- .self$current_value + 1
        } else {
          return(.self$current_value)
        }
      }
    }
  )
)

main <- function() {
  text <- '1 2 3 4 5 6 7 8 9 10'
  tokenizer <- new("Tokenizer", text = text)
  analyzer <- new("SequenceAnalyzer", tokenizer = tokenizer)
  generator <- new("SequenceGenerator", analyzer = analyzer)
  while (TRUE) {
    print(generator$generate())
  }
}

main()