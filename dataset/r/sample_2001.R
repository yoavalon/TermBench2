library(stringr)

Tokenizer <- R6::R6Class("Tokenizer",
  public = list(
    text = NULL,
    tokens = NULL,
    initialize = function(text) {
      self$text <- text
      self$tokens <- NULL
    },
    tokenize = function() {
      self$tokens <- str_extract_all(self$text, "\\b\\w+\\b")[[1]]
    },
    get_tokens = function() {
      return(self$tokens)
    }
  )
)

PrecisionAnalyzer <- R6::R6Class("PrecisionAnalyzer",
  public = list(
    tokens = NULL,
    precision_issues = NULL,
    initialize = function(tokens) {
      self$tokens <- tokens
      self$precision_issues <- NULL
    },
    analyze = function() {
      for (token in self$tokens) {
        if (self$is_float(token)) {
          self$check_precision(token)
        }
      }
    },
    is_float = function(token) {
      return(!is.na(as.numeric(token)))
    },
    check_precision = function(token) {
      if (grepl("\\.", token)) {
        decimal_part <- str_split(token, "\\.")[[1]][[2]]
        if (nchar(decimal_part) > 6) {
          self$precision_issues <<- c(self$precision_issues, token)
        }
      }
    },
    get_issues = function() {
      return(self$precision_issues)
    }
  )
)

main <- function() {
  text <- 'In the year 2023, the global temperature was 15.2345678 degrees Celsius. The precision is critical.'
  tokenizer <- Tokenizer$new(text)
  tokenizer$tokenize()
  tokens <- tokenizer$get_tokens()
  analyzer <- PrecisionAnalyzer$new(tokens)
  analyzer$analyze()
  issues <- analyzer$get_issues()
  cat('Tokens with precision issues:', issues, '\n')
}

main()