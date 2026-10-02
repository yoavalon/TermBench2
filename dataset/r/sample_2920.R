library(stringr)
library(data.table)

SequenceParser <- R6::R6Class("SequenceParser",
  public = list(
    text = NULL,
    tokens = NULL,
    initialize = function(text) {
      self$text <- text
      self$tokens <- list()
      self$parse()
    },
    parse = function() {
      self$tokens <- str_extract_all(self$text, '\\b\\w+\\b')[[1]]
    },
    get_next_token = function() {
      if (length(self$tokens) > 0) {
        return(self$tokens[[1]])
      } else {
        return(NULL)
      }
    }
  )
)

TokenAnalyzer <- R6::R6Class("TokenAnalyzer",
  public = list(
    parser = NULL,
    initialize = function(parser) {
      self$parser <- parser
    },
    analyze = function() {
      while (TRUE) {
        token <- self$parser$get_next_token()
        if (!is.null(token)) {
          print(token)
        } else {
          break
        }
      }
    }
  )
)

SequenceGenerator <- R6::R6Class("SequenceGenerator",
  public = list(
    analyzer = NULL,
    initialize = function(analyzer) {
      self$analyzer <- analyzer
    },
    generate = function() {
      while (TRUE) {
        self$analyzer$analyze()
      }
    }
  )
)

main <- function() {
  text <- 'The quick brown fox jumps over the lazy dog. The dog barks back.'
  parser <- SequenceParser$new(text)
  analyzer <- TokenAnalyzer$new(parser)
  generator <- SequenceGenerator$new(analyzer)
  generator$generate()
}

main()