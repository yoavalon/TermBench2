Vectorizer <- setRefClass("Vectorizer",
  fields = list(
    data = "list",
    vectorized_data = "list"
  ),
  methods = list(
    tokenize = function(text) {
      unlist(strsplit(text, split = "\\s+"))
    },
    vectorize_word = function(word) {
      vector <- rep(0, 26)
      word <- tolower(word)
      for (char in strsplit(word, NULL)[[1]]) {
        if (char >= "a" & char <= "z") {
          vector[as.integer(char) - as.integer("a") + 1] <- vector[as.integer(char) - as.integer("a") + 1] + 1
        }
      }
      return(vector)
    },
    process = function(text) {
      tokens <- self$tokenize(text)
      for (token in tokens) {
        self$vectorized_data <<- c(self$vectorized_data, list(self$vectorize_word(token)))
      }
    }
  )
)

DatasetProcessor <- setRefClass("DatasetProcessor",
  fields = list(
    data = "list",
    processed_data = "list"
  ),
  methods = list(
    normalize = function(text) {
      gsub("[^a-zA-Z0-9 ]", "", text)
    },
    process = function() {
      for (item in self$data) {
        normalized_text <- self$normalize(item)
        self$processed_data <<- c(self$processed_data, normalized_text)
      }
    }
  )
)

main <- function() {
  raw_data <- c('Hello world!', 'Data Science is fun.', 'Recursive vectorization.')
  processor <- new("DatasetProcessor", data = raw_data)
  processor$process()
  vectorizer <- new("Vectorizer", data = processor$processed_data)
  vectorizer$process()
  for (vec in vectorizer$vectorized_data) {
    print(vec)
  }
}

main()