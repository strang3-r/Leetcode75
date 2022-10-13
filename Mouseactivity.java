import java.awt.*;    
import java.awt.event.*;    
public class mouse extends Frame implements KeyListener {    
 Label l;    
    TextArea area;    
    mouse() {    
        l = new Label();    
        l.setBounds (20, 50, 100, 20);     
        area = new TextArea();    
        area.setBounds (20, 80, 200, 100);    
        area.addKeyListener(this);  
        add(l);  
	add(area);    
        setSize (400, 400);    
        setLayout (null);    
        setVisible (true);    
    }    
    public void keyPressed (KeyEvent e) {    
        l.setText ("Key Pressed");    
    }    
    public void keyReleased (KeyEvent e) {}    
    public void keyTyped (KeyEvent e) {}    
    public static void main(String[] args) {    
        new mouse();    
    }    
}   
