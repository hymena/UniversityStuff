import xml.etree.ElementTree as ET


def depth_iter(element, tag = None):
    stack = []
    stack.append(iter([element]))
    while stack:
        e = next(stack[-1], None)
        if e == None:
            stack.pop()
        else:
            stack.append(iter(e))
            if tag == None or e.tag == tag:
                e.set('lvl',f'{len(stack)-1}')
                yield(e.atrib['path'], len(stack)-1 )


def create_absolute_paths(root):
    old_level = 0
    path_stack = []
    for child in root.iter():
        level = int(child.attrib['lvl'])
        if level > old_level:
            path_stack.append(child.attrib['path'])
        else:
            while(old_level >= level):
                path_stack.pop()
                old_level -= 1
            path_stack.append(child.attrib['path'])

        old_level = level
        child.set('completePath','/'.join(path_stack))

def parse_xml(src):
    return ET.parse(src)