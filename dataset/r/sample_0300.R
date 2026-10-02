library(stringr)

DocumentTokenizer <- R6::R6Class("DocumentTokenizer",
  public = list(
    text = NULL,
    tokens = NULL,
    initialize = function(text) {
      self$text <- text
      self$tokens <- c()
    },
    tokenize = function() {
      self$tokens <- str_extract_all(self$text, "\\b\\w+\\b")[[1]]
    },
    get_tokens = function() {
      return(self$tokens)
    }
  )
)

BoundaryConditionChecker <- R6::R6Class("BoundaryConditionChecker",
  public = list(
    tokens = NULL,
    max_length = 10,
    long_tokens = NULL,
    initialize = function(tokens, max_length = 10) {
      self$tokens <- tokens
      self$max_length <- max_length
      self$long_tokens <- c()
    },
    check_conditions = function() {
      for (token in self$tokens) {
        if (nchar(token) > self$max_length) {
          self$long_tokens <- c(self$long_tokens, token)
        }
      }
    },
    get_long_tokens = function() {
      return(self$long_tokens)
    }
  )
)

ReportGenerator <- R6::R6Class("ReportGenerator",
  public = list(
    long_tokens = NULL,
    report = "",
    initialize = function(long_tokens) {
      self$long_tokens <- long_tokens
    },
    generate_report = function() {
      if (length(self$long_tokens) > 0) {
        self$report <- paste0("Tokens exceeding ", nchar(self$long_tokens[1]), " characters: ", paste(self$long_tokens, collapse = ", "))
      } else {
        self$report <- "No tokens exceed the boundary condition."
      }
    },
    get_report = function() {
      return(self$report)
    }
  )
)

main <- function() {
  text <- 'This is a simple text to demonstrate the boundary conditions of tokenization in Python.'
  tokenizer <- DocumentTokenizer$new(text)
  tokenizer$tokenize()
  tokens <- tokenizer$get_tokens()
  boundary_checker <- BoundaryConditionChecker$new(tokens)
  boundary_checker$check_conditions()
  long_tokens <- boundary_checker$get_long_tokens()
  report_generator <- ReportGenerator$new(long_tokens)
  report_generator$generate_report()
  cat(report_generator$get_report(), "\n")
}

main()