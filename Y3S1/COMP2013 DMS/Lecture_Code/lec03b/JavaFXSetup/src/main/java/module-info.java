module com.example.javafxsetup {
    requires javafx.controls;
    requires javafx.fxml;


    opens com.COMP2013 to javafx.fxml;
    exports com.COMP2013;
}