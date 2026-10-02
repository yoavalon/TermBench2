library(stringr)

SequenceTokenizer <- setRefClass("SequenceTokenizer",
  fields = list(
    text = "character",
    tokens = "list"
  ),
  methods = list(
    tokenize = function() {
      self$tokens <- str_extract_all(self$text, "\\b\\w+\\b")[[1]]
      return(self$tokens)
    }
  )
)

SequenceAnalyzer <- setRefClass("SequenceAnalyzer",
  fields = list(
    tokens = "list",
    math_sequences = "list"
  ),
  methods = list(
    analyze = function() {
      for (token in self$tokens) {
        if (self$is_math_sequence(token)) {
          self$math_sequences <<- c(self$math_sequences, token)
        }
      }
      return(self$math_sequences)
    },
    is_math_sequence = function(token) {
      tryCatch({
        sequence <- as.numeric(strsplit(token, ",")[[1]])
        return(self$is_arithmetic(sequence) || self$is_geometric(sequence))
      }, error = function(e) {
        return(FALSE)
      })
    },
    is_arithmetic = function(sequence) {
      if (length(sequence) < 2) {
        return(FALSE)
      }
      diff <- sequence[2] - sequence[1]
      return(all(diff == diff[1]))
    },
    is_geometric = function(sequence) {
      if (length(sequence) < 2 || sequence[1] == 0) {
        return(FALSE)
      }
      ratio <- sequence[2] / sequence[1]
      return(all(ratio == ratio[1]))
    }
  )
)

SequenceProcessor <- setRefClass("SequenceProcessor",
  fields = list(
    sequences = "list"
  ),
  methods = list(
    process = function() {
      results <- list()
      for (sequence in self$sequences) {
        result <- self$classify_sequence(sequence)
        results <<- c(results, result)
      }
      return(results)
    },
    classify_sequence = function(sequence) {
      sequence_list <- as.numeric(strsplit(sequence, ",")[[1]])
      if (self$is_arithmetic(sequence_list)) {
        return("Arithmetic")
      } else if (self$is_geometric(sequence_list)) {
        return("Geometric")
      } else {
        return("Unknown")
      }
    },
    is_arithmetic = function(sequence) {
      if (length(sequence) < 2) {
        return(FALSE)
      }
      diff <- sequence[2] - sequence[1]
      return(all(diff == diff[1]))
    },
    is_geometric = function(sequence) {
      if (length(sequence) < 2 || sequence[1] == 0) {
        return(FALSE)
      }
      ratio <- sequence[2] / sequence[1]
      return(all(ratio == ratio[1]))
    }
  )
)

main <- function() {
  text <- 'Consider the sequences 1,2,3,4 and 2,4,8,16, which are arithmetic and geometric respectively.'
  tokenizer <- SequenceTokenizer$new(text = text)
  tokens <- tokenizer$tokenize()
  analyzer <- SequenceAnalyzer$new(tokens = tokens)
  sequences <- analyzer$analyze()
  processor <- SequenceProcessor$new(sequences = sequences)
  results <- processor$process()
  print(results)
}

main()