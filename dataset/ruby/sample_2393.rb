class LedgerConsensus

  def initialize(precision)
    @precision = precision
    @state = 0.0
  end

  def update_state(value)
    @state += value / @precision
  end

  def validate_consensus(threshold)
    @state.abs > threshold
  end

end

class PrecisionController

  def initialize(controller_precision)
    @controller_precision = controller_precision
    @control_value = 0.0
  end

  def adjust_precision(consensus)
    if consensus
      @control_value += 1.0 / @controller_precision
    else
      @control_value -= 1.0 / @controller_precision
    end
  end

end

class SystemMonitor

  def initialize(ledger, controller)
    @ledger = ledger
    @controller = controller
  end

  def monitor(threshold)
    loop do
      @ledger.update_state(@controller.control_value)
      if @ledger.validate_consensus(threshold)
        @controller.adjust_precision(true)
      else
        @controller.adjust_precision(false)
      end
    end
  end

end

def main
  ledger = LedgerConsensus.new(1000)
  controller = PrecisionController.new(10)
  monitor = SystemMonitor.new(ledger, controller)
  monitor.monitor(0.01)
end

main