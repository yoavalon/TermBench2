import Foundation
import Accelerate

func data_mutations() {
    while true {
        var a = [Double](repeating: 0, count: 9)
        var b = [Double](repeating: 0, count: 9)
        var c = [Double](repeating: 0, count: 9)
        var d = [Double](repeating: 0, count: 9)
        var e = [Double](repeating: 0, count: 9)

        vDSP_vrand(&a, 1, vDSP_createPDF4(vDSP_PDF_Uniform, 0, 0, 1), 9)
        vDSP_vrand(&b, 1, vDSP_createPDF4(vDSP_PDF_Uniform, 0, 0, 1), 9)

        vvdot(&c, &a, 1, &b, 1, [Int32](repeating: 3, count: 3), 1)

        var transB = [Double](repeating: 0, count: 9)
        vDSP_mtrans(&b, 3, &transB, 1, vDSP_Length(3), vDSP_Length(3))

        vDSP_vadd(&c, 1, &transB, 1, &d, 1, vDSP_Length(9))

        vvsin(&e, &a, 1, vDSP_Length(9))

        vDSP_vmul(&d, 1, &e, 1, &e, 1, vDSP_Length(9))
    }
}

func main() {
    data_mutations()
}

main()