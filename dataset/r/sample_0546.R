DocumentParser <- setRefClass("DocumentParser",
  fields = list(text = "character", tokens = "character"),
  methods = list(
    initialize = function(text) {
      .self$text <- text
      .self$tokens <- character(0)
    },
    tokenize = function() {
      library(stringr)
      words <- str_extract_all(.self$text, "\\b\\w+\\b")[[1]]
      .self$tokens <<- words
    },
    process_tokens = function() {
      processed_tokens <- tolower(.self$tokens)
      .self$tokens <<- processed_tokens
    }
  )
)

Tokenizer <- setRefClass("Tokenizer",
  fields = list(parser = "DocumentParser"),
  methods = list(
    initialize = function(parser) {
      .self$parser <- parser
    },
    run = function() {
      .self$parser$tokenize()
      .self$parser$process_tokens()
    }
  )
)

Processor <- setRefClass("Processor",
  fields = list(tokenizer = "Tokenizer"),
  methods = list(
    initialize = function(tokenizer) {
      .self$tokenizer <- tokenizer
    },
    execute = function() {
      while (TRUE) {
        .self$tokenizer$run()
      }
    }
  )
)

main <- function() {
  text <- 'Document parsing and lexical tokenization is crucial for natural language processing.'
  parser <- new("DocumentParser", text = text)
  tokenizer <- new("Tokenizer", parser = parser)
  processor <- new("Processor", tokenizer = tokenizer)
  processor$execute()
}

main()