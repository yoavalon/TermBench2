use std::f64::consts::PI;
use std::time::Duration;
use std::thread;
use plotters::prelude::*;

fn calculate_altitude(t: f64) -> f64 {
    let g = 9.81;
    let v0 = 300.0;
    let h0 = 10000.0;
    h0 + v0 * t - 0.5 * g * t.powi(2)
}

fn plot_trajectory() {
    let root_area = BitMapBackend::new("trajectory.png", (640, 480)).into_drawing_area();
    root_area.fill(&WHITE).unwrap();

    let mut chart = ChartBuilder::on(&root_area)
        .caption("Flight Trajectory", ("sans-serif", 50).into_font())
        .margin(10)
        .x_label_area_size(30)
        .y_label_area_size(30)
        .build_cartesian_2d(0f64..1000f64, 0f64..10000f64)
        .unwrap();

    chart.configure_mesh().draw().unwrap();

    let mut t = 0.0;
    while t <= 1000.0 {
        let h = calculate_altitude(t);
        if h < 0.0 {
            break;
        }
        chart.draw_series(std::iter::once(PointSeries::of_element(
            vec![(t, h)],
            5,
            &RED,
            &Circle,
        )))
        .unwrap();

        root_area.present().unwrap();
        thread::sleep(Duration::from_millis(10));
        t += 1.0;
    }
}

fn main() {
    plot_trajectory();
}