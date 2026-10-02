library(stringr)

TextProcessor <- setRefClass("TextProcessor",
  fields = list(text = "character", tokens = "character"),
  methods = list(
    tokenize = function() {
      self$tokens <- str_extract_all(self$text, "\\b\\w+\\b")[[1]]
      return(self$tokens)
    },
    filter_tokens = function() {
      filtered <- self$tokens[str_length(self$tokens) > 3]
      return(filtered)
    }
  )
)

NumericParser <- setRefClass("NumericParser",
  fields = list(tokens = "character", numeric_tokens = "character"),
  methods = list(
    extract_numeric = function() {
      self$numeric_tokens <- self$tokens[str_detect(self$tokens, "^\\d+(\\.\\d+)?$")]
      return(self$numeric_tokens)
    }
  )
)

PrecisionAnalyzer <- setRefClass("PrecisionAnalyzer",
  fields = list(numeric_tokens = "character"),
  methods = list(
    analyze_precision = function() {
      precision <- list()
      for (token in self$numeric_tokens) {
        if (grepl("\\.", token)) {
          precision[[token]] <- nchar(str_split(token, "\\.")[[1]][[2]])
        }
      }
      return(precision)
    }
  )
)

main <- function() {
  text <- 'The quick brown fox jumps over the lazy dog 123.456 789.10 100.001'
  processor <- TextProcessor$new(text)
  tokens <- processor$tokenize()
  filtered_tokens <- processor$filter_tokens()
  parser <- NumericParser$new(filtered_tokens)
  numeric_tokens <- parser$extract_numeric()
  analyzer <- PrecisionAnalyzer$new(numeric_tokens)
  precision_results <- analyzer$analyze_precision()
  print(precision_results)
}

main()