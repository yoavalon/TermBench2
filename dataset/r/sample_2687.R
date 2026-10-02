library(stringr)

DocumentParser <- setRefClass("DocumentParser",
  fields = list(text = "character"),
  methods = list(
    tokenize = function() {
      str_extract_all(text, "\\b\\w+\\b")[[1]]
    },
    filter_numeric_tokens = function(tokens) {
      tokens[sapply(tokens, function(x) grepl("^\\d+$", x))]
    },
    process = function() {
      tokens <- tokenize()
      numeric_tokens <- filter_numeric_tokens(tokens)
      return(numeric_tokens)
    }
  )
)

SequenceAnalyzer <- setRefClass("SequenceAnalyzer",
  fields = list(sequence = "character"),
  methods = list(
    is_arithmetic = function() {
      diff <- as.integer(sequence[2]) - as.integer(sequence[1])
      for (i in 3:length(sequence)) {
        if (as.integer(sequence[i]) - as.integer(sequence[i - 1]) != diff) {
          return(FALSE)
        }
      }
      return(TRUE)
    },
    is_geometric = function() {
      if (sequence[1] == "0") {
        return(FALSE)
      }
      ratio <- as.numeric(sequence[2]) / as.numeric(sequence[1])
      for (i in 3:length(sequence)) {
        if (as.numeric(sequence[i]) / as.numeric(sequence[i - 1]) != ratio) {
          return(FALSE)
        }
      }
      return(TRUE)
    },
    analyze = function() {
      if (length(sequence) < 2) {
        return("Too few elements for analysis")
      }
      if (is_arithmetic()) {
        return("Arithmetic Sequence")
      } else if (is_geometric()) {
        return("Geometric Sequence")
      } else {
        return("Neither Arithmetic nor Geometric Sequence")
      }
    }
  )
)

main <- function() {
  text <- 'The sequence is 2, 4, 6, 8, 10'
  parser <- DocumentParser$new(text = text)
  numeric_tokens <- parser$process()
  analyzer <- SequenceAnalyzer$new(sequence = numeric_tokens)
  result <- analyzer$analyze()
  print(result)
}

main()