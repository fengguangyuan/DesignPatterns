import java.util.List;
import java.util.ArrayList;

/**
 * Listener / Event has the similar structure.
 */

abstract class Subject {
    private List<Observer> observers = new ArrayList<Observer>();

    // Attach an observer to the subject
    public void attach(Observer ob) {
        observers.add(ob);
    }

    // Detach an observer from the subject
    public void detach(Observer ob) {
        observers.remove(ob);
    }

    // Notify all the observers, but only the related observer will take actions
    public void notifyObs() {
        for(Observer it : observers) ((ConcreteObserver)it).update();
    }
}

class ConcreteSubject extends Subject {
    private String subjectState;
    public String getState() { return subjectState; }
    public void setState(String value) { subjectState = value; }

}

/* The interface for the concrete observers, the definition of a update method is included*/
abstract class Observer {
    public abstract void update();
}
class ConcreteObserver extends Observer {
    private Subject subject;
    private String name;
    // keep consistent with subject state
    private String observerState;
    public ConcreteObserver(ConcreteSubject subject, String name) {
        this.subject = subject;
        this.name = name;
    }

    @Override
    public void update() {
        this.observerState = ((ConcreteSubject)subject).getState();
        System.out.println(name + "'s state is " + observerState);
    }
}

public class ObserverPattern {

public static void main(String[] args) {
    ConcreteSubject sub = new ConcreteSubject();
    sub.attach(new ConcreteObserver(sub, "Observer1"));
    sub.attach(new ConcreteObserver(sub, "Observer2"));
    sub.attach(new ConcreteObserver(sub, "Observer3"));

    sub.setState("DONE");
    sub.notifyObs();
}

}
