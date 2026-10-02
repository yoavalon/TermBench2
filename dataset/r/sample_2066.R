library(stringr)

Tokenizer <- setRefClass("Tokenizer",
  fields = list(
    text = "character",
    tokens = "character"
  ),
  methods = list(
    tokenize = function() {
      self$tokens <- str_extract_all(self$text, "\\b\\w+\\b")[[1]]
    },
    get_tokens = function() {
      return(self$tokens)
    }
  )
)

DocumentParser <- setRefClass("DocumentParser",
  fields = list(
    text = "character",
    tokenizer = "Tokenizer"
  ),
  methods = list(
    initialize = function(text) {
      .self$text <- text
      .self$tokenizer <- Tokenizer$new(text = text)
    },
    parse = function() {
      self$tokenizer$tokenize()
    },
    get_parsed_tokens = function() {
      return(self$tokenizer$get_tokens())
    }
  )
)

AnalysisEngine <- setRefClass("AnalysisEngine",
  fields = list(
    tokens = "character"
  ),
  methods = list(
    initialize = function(tokens) {
      .self$tokens <- tokens
    },
    analyze = function() {
      float_tokens <- self$tokens[str_detect(self$tokens, "^\\d+\\.\\d+$")]
      return(float_tokens)
    }
  )
)

main <- function() {
  text <- 'In this document, we have 3.14 and 2.71828 as floating point numbers.'
  parser <- DocumentParser$new(text = text)
  parser$parse()
  tokens <- parser$get_parsed_tokens()
  analyzer <- AnalysisEngine$new(tokens = tokens)
  float_tokens <- analyzer$analyze()
  cat('Floating point tokens:', paste(float_tokens, collapse = ', '), '\n')
}

main()