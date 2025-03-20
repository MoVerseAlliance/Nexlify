nclude <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QTabBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <QIcon>

class Nexlify : public QMainWindow {
    Q_OBJECT
public:
    Nexlify(QWidget *parent = nullptr) : QMainWindow(parent) {
        setWindowTitle("Nexlify");
        resize(1280, 720);

        QWidget *centralWidget = new QWidget(this);
        QVBoxLayout *layout = new QVBoxLayout(centralWidget);
        setCentralWidget(centralWidget);

        QMenuBar *menuBar = new QMenuBar(this);
        QMenu *fileMenu = menuBar->addMenu("菜单");
        fileMenu->addAction("保存", this, [](){ qDebug("保存"); });
        fileMenu->addAction("撤销", this, [](){ qDebug("撤销"); });
        fileMenu->addAction("偏好设置", this, [](){ qDebug("偏好设置"); });
        fileMenu->addAction("关于", this, [](){ qDebug("关于 Nexlify"); });
        layout->addWidget(menuBar);

        workspace = new QWidget(this);
        layout->addWidget(workspace);

        QTabBar *workflowBar = new QTabBar(this);
        workflowBar->addTab(QIcon(":/icons/space.png"), "创作空间");
        workflowBar->addTab(QIcon(":/icons/hub.png"), "资源中心");
        workflowBar->addTab(QIcon(":/icons/tools.png"), "增强工具");
        workflowBar->addTab(QIcon(":/icons/world.png"), "互动世界");
        workflowBar->addTab(QIcon(":/icons/platform.png"), "协作平台");
        workflowBar->addTab(QIcon(":/icons/center.png"), "输出中心");
        workflowBar->addTab(QIcon(":/icons/ai.png"), "AI舱");

        workflowBar->setStyleSheet("QTabBar::tab { height: 50px; width: 180px; font-size: 14px; background: #2c2c2c; color: #e0e0e0; } QTabBar::tab:selected { background: #ff8c00; }");
        layout->addWidget(workflowBar);

        connect(workflowBar, &QTabBar::currentChanged, this, &Nexlify::switchWorkflow);
    }

private slots:
    void switchWorkflow(int index) {
        QString workflow;
        switch (index) {
            case 0: workflow = "创作空间"; break;
            case 1: workflow = "资源中心"; break;
            case 2: workflow = "增强工具"; break;
            case 3: workflow = "互动世界"; break;
            case 4: workflow = "协作平台"; break;
            case 5: workflow = "输出中心"; break;
            case 6: workflow = "AI舱"; break;
        }
        statusBar()->showMessage("当前工作流: " + workflow);
    }

private:
    QWidget *workspace;
};

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    Nexlify window;
    window.show();
    return app.exec();
}

#include "main.moc"
