library(pracma)

Vectorizer <- setRefClass("Vectorizer",
                          fields = list(sequence = "numeric", vector = "numeric"),
                          methods = list(
                            process = function() {
                              self$vectorize()
                              self$normalize()
                            },
                            vectorize = function() {
                              for (item in self$sequence) {
                                self$vector <- c(self$vector, sin(item))
                              }
                            },
                            normalize = function() {
                              total <- sum(self$vector)
                              self$vector <- self$vector / total
                            }
                          ))

SequenceGenerator <- setRefClass("SequenceGenerator",
                                fields = list(index = "numeric"),
                                methods = list(
                                  next = function() {
                                    self$index <- self$index + 1
                                    return(sqrt(self$index))
                                  }
                                ))

Processor <- setRefClass("Processor",
                        fields = list(generator = "SequenceGenerator"),
                        methods = list(
                          run = function() {
                            while (TRUE) {
                              sequence <- replicate(100, self$generator$next())
                              vectorizer <- Vectorizer$new(sequence = sequence)
                              vectorizer$process()
                              print(vectorizer$vector)
                            }
                          }
                        ))

main <- function() {
  processor <- Processor$new()
  processor$run()
}

main()