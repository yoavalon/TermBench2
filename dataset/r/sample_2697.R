library(stringr)

Tokenizer <- setRefClass("Tokenizer",
  fields = list(
    text = "character",
    tokens = "character"
  ),
  methods = list(
    tokenize = function() {
      self$tokens <- str_extract_all(self$text, "\\b\\w+\\b")[[1]]
      return(self$tokens)
    }
  )
)

Sequencer <- setRefClass("Sequencer",
  fields = list(
    tokens = "character",
    sequence = "numeric"
  ),
  methods = list(
    generate_sequence = function() {
      self$sequence <- as.numeric(self$tokens[grepl("^\\d+$", self$tokens)])
      return(self$sequence)
    }
  )
)

Analyzer <- setRefClass("Analyzer",
  fields = list(
    sequence = "numeric",
    result = "numeric"
  ),
  methods = list(
    analyze = function() {
      if (length(self$sequence) > 0) {
        self$result <- c(sum(self$sequence), min(self$sequence), max(self$sequence), length(self$sequence))
      }
      return(self$result)
    }
  )
)

main <- function() {
  text <- 'The quick brown fox jumps over 13 lazy dogs and 7 cats.'
  tokenizer <- Tokenizer$new(text = text)
  tokens <- tokenizer$tokenize()
  sequencer <- Sequencer$new(tokens = tokens)
  sequence <- sequencer$generate_sequence()
  analyzer <- Analyzer$new(sequence = sequence)
  result <- analyzer$analyze()
  print(result)
}

main()