library(stringr)

DocumentParser <- setRefClass(
  "DocumentParser",
  fields = list(
    text = "character",
    tokens = "list"
  ),
  methods = list(
    initialize = function(text) {
      .self$text <- text
      .self$tokens <- list()
      .self$process_text()
    },
    process_text = function() {
      .self$tokenize()
    },
    tokenize = function() {
      .self$tokens <- str_extract_all(tolower(.self$text), "\\b\\w+\\b")[[1]]
    }
  )
)

TokenAnalyzer <- setRefClass(
  "TokenAnalyzer",
  fields = list(
    tokens = "list",
    token_count = "list"
  ),
  methods = list(
    initialize = function(tokens) {
      .self$tokens <- tokens
      .self$token_count <- list()
      .self$analyze_tokens()
    },
    analyze_tokens = function() {
      for (token in .self$tokens) {
        if (token %in% names(.self$token_count)) {
          .self$token_count[[token]] <- .self$token_count[[token]] + 1
        } else {
          .self$token_count[[token]] <- 1
        }
      }
    }
  )
)

ReportGenerator <- setRefClass(
  "ReportGenerator",
  fields = list(
    token_count = "list",
    report = "list"
  ),
  methods = list(
    initialize = function(token_count) {
      .self$token_count <- token_count
      .self$report <- .self$generate_report()
    },
    generate_report = function() {
      report <- sort(.self$token_count, decreasing = TRUE)
      return(report)
    }
  )
)

main <- function() {
  text <- 'This is a test document. This document is used for testing tokenization and analysis.'
  parser <- DocumentParser$new(text)
  analyzer <- TokenAnalyzer$new(parser$tokens)
  report_generator <- ReportGenerator$new(analyzer$token_count)
  print(report_generator$report)
}

main()